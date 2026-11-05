import numpy as np
from mpi4py import MPI
import sys

# ===================================================================
# CONFIGURAÇÃO E FUNÇÕES DE APOIO
# ===================================================================

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()


def print_matriz_formatada(matriz, titulo="Matriz"):
    """ 
    Imprime uma matriz NumPy 
    """
    if matriz.size == 0:
        print(f"\n{titulo} (vazia)")
        return

    print(f"\n{titulo} (Tamanho {matriz.shape[0]}x{matriz.shape[1]}):")
    
    linhas_str = []
    for linha in matriz:
        linha_formatada = " ".join([f"{num:10f}" for num in linha])
        linhas_str.append(f"   {linha_formatada} ")
        
    print("\n".join(linhas_str))


def determinante_recursivo(matriz):
    """ 
    Calcula o determinante de uma matriz usando a expansão de Laplace de forma recursiva. 
    """
    n = matriz.shape[0]
    if n == 0:
        return 1.0
    if n == 1:
        return matriz[0, 0]
    if n == 2:
        return matriz[0, 0] * matriz[1, 1] - matriz[0, 1] * matriz[1, 0]

    det = 0
    for j in range(n):
        sub_matriz = np.delete(np.delete(matriz, 0, axis=0), j, axis=1)
        sinal = (-1) ** j
        det += sinal * matriz[0, j] * determinante_recursivo(sub_matriz)
    return det

def parallel_matrix_multiply(matA, matB):
    """
    Função do mestre para orquestrar uma multiplicação de matriz paralela.
    """
    task_data = {'task': 'MULTIPLY', 'matrix_B': matB}
    comm.bcast(task_data, root=0)

    rows_to_split = np.array_split(matA, size - 1)
    
    for i in range(len(rows_to_split)):
        slave_rank = i + 1
        comm.send(rows_to_split[i], dest=slave_rank, tag=1)

    results = []
    for i in range(len(rows_to_split)):
        slave_rank = i + 1
        result_part = comm.recv(source=slave_rank, tag=2)
        results.append(result_part)

    return np.vstack(results)


# ===================================================================
# MESTRE E ESCRAVOS
# ===================================================================

def run_schur_on_matrix(M):
    """
    Contém a lógica principal do Mestre para executar o algoritmo de Schur
    """
    print_matriz_formatada(M, titulo="Matriz M")

    n = M.shape[0] // 2
    A = M[:n, :n]
    B = M[:n, n:]
    C = M[n:, :n]
    D = M[n:, n:]

    det_A = determinante_recursivo(A)
    print(f"\nDeterminante de A: {det_A:.2f}")

    if np.abs(det_A) < 1e-9:
        print("A matriz A nao e invertivel. Abortando.")
        return

    print("\nCalculando A^-1 em paralelo...")
    task_data = {'task': 'INVERSE', 'matrix': A}
    comm.bcast(task_data, root=0)
    
    cofactor_matrix = np.empty_like(A)
    num_cofactors = n * n
    for _ in range(num_cofactors):
        source_rank, cofactor_val, pos_i, pos_j = comm.recv(source=MPI.ANY_SOURCE, tag=1)
        cofactor_matrix[pos_i, pos_j] = cofactor_val
            
    adj_A = cofactor_matrix.T
    A_inv = adj_A / det_A

    print("Calculando C * A^-1 em paralelo...")
    C_A_inv = parallel_matrix_multiply(C, A_inv)

    print("Calculando (C * A^-1) * B em paralelo...")
    term = parallel_matrix_multiply(C_A_inv, B)
    
    schur_complement = D - term
    det_schur = determinante_recursivo(schur_complement)
    print(f"Determinante do Complemento de Schur: {det_schur:.2f}")

    final_det = det_A * det_schur
    
    print("\n=======================================================")
    print(f"Determinante Final de M: {final_det:.2f}")
    print("=======================================================")



def slave_process():
    """
    Lógica executada por todos os processos escravos (rank > 0).
    """
    while True:
        task_data = comm.bcast(None, root=0)
        task = task_data.get('task')

        if task == 'DIE':
            break

        elif task == 'INVERSE':
            A = task_data.get('matrix')
            n = A.shape[0]
            for i in range(rank - 1, n, size - 1):
                for j in range(n):
                    sub_matrix = np.delete(np.delete(A, i, axis=0), j, axis=1)
                    minor = determinante_recursivo(sub_matrix)
                    cofactor = ((-1)**(i + j)) * minor
                    comm.send((rank, cofactor, i, j), dest=0, tag=1)

        elif task == 'MULTIPLY':
            B = task_data.get('matrix_B')
            A_part = comm.recv(source=0, tag=1)
            if A_part.shape[0] > 0:
                result_part = A_part @ B
                comm.send(result_part, dest=0, tag=2)
            else:
                n_cols = B.shape[1]
                empty_result = np.empty((0, n_cols), dtype=float)
                comm.send(empty_result, dest=0, tag=2)


# ===================================================================
# PONTO DE ENTRADA PRINCIPAL
# ===================================================================
if __name__ == '__main__':
    if size < 2:
        if rank == 0:
            print("Erro: Este programa requer pelo menos 2 processos.", file=sys.stderr)
    
    elif rank == 0: # Mestre 
        M = None
        matrix_size = 0
        
        if len(sys.argv) < 2:
            print("Erro: Modo de operação não especificado.", file=sys.stderr)
            comm.Abort()
        
        try:
            mode = int(sys.argv[1])
            if mode == 0:
                if len(sys.argv) < 3:
                    print("Erro: Tamanho da matriz não especificado para o modo 0.", file=sys.stderr)
                    comm.Abort()
                matrix_size = int(sys.argv[2])
            elif mode == 1:
                M_hardcoded = np.array([
                    [10.0, 2.0, 1.0, 1.0], 
                    [3.0, 10.0, 4.0, 1.0],
                    [3.0, 1.0, 2.0, 9.0], 
                    [2.0, 9.0, 7.0, 2.0]
                ], dtype=float)
                matrix_size = M_hardcoded.shape[0]
            else:
                print(f"Erro: Modo '{mode}' inválido. Use 0 ou 1.", file=sys.stderr)
                comm.Abort()
        
        except (ValueError, IndexError):
            print("Erro: Argumento inválido.", file=sys.stderr)
            comm.Abort()

        if matrix_size % 2 != 0 or matrix_size == 0:
            print(f"Erro: O tamanho da matriz ({matrix_size}) deve ser um número par e maior que zero.", file=sys.stderr)
            comm.Abort()
            
        if mode == 0:
            M = np.random.rand(matrix_size, matrix_size) * 10
        elif mode == 1:
            M = M_hardcoded

        run_schur_on_matrix(M)
        comm.bcast({'task': 'DIE'}, root=0)

    else: # Escravo apenas espera
        slave_process()