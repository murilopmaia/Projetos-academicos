import numpy as np

def gaussian_elimination_backward_substitution(n, A):
    """
    Resolve o sistema linear nxn usando Eliminação de Gauss com Substituição Reversa.
    :param n: número de equações e incógnitas.
    :param A: matriz aumentada [A | b] de dimensão n x (n+1).
    :return: lista com a solução [x_1, ..., x_n] ou None.
    """
    # Passo 1:
    for i in range(n - 1):
        # Passo 2:
        p = -1
        for k in range(i, n):
            if A[k][i] != 0:
                p = k
                break

        if p == -1:
            print("no unique solution exists")
            return None

        # Passo 3:
        if p != i:
            A[p], A[i] = A[i], A[p]

        # Passo 4
        for j in range(i + 1, n):
            # Passo 5
            m_ji = A[j][i] / A[i][i]
            # Passo 6:
            for k in range(n + 1):
                A[j][k] = A[j][k] - m_ji * A[i][k]

    # Passo 7
    if A[n - 1][n - 1] == 0:
        print("no unique solution exists")
        return None

    # Passo 8:
    x = [0.0] * n
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1]

    # Passo 9
    for i in range(n - 2, -1, -1):
        soma = sum(A[i][j] * x[j] for j in range(i + 1, n))
        x[i] = (A[i][n] - soma) / A[i][i]

    # Passo 10:
    return x

def gaussian_elimination_partial_pivoting(n, A):
 
   
    """
    Resolve o sistema linear nxn usando Eliminação de Gauss com Pivoteamento Parcial.
    :param n: número de equações e incógnitas.
    :param A: matriz aumentada [A | b] de dimensão n x (n+1).
    :return: lista com a solução [x_1, ..., x_n] ou None.

    """
    # Passo 1:
    NROW = [i for i in range(n)]

    # Passo 2:
    for i in range(n - 1):
        # Passo 3:
        p = i
        max_val = abs(A[NROW[i]][i])
        for j in range(i + 1, n):
            if abs(A[NROW[j]][i]) > max_val:
                max_val = abs(A[NROW[j]][i])
                p = j

        # Passo 4
        if A[NROW[p]][i] == 0:
            print("no unique solution exists")
            return None

        # Passo 5:
        if NROW[i] != NROW[p]:
            NCOPY = NROW[i]
            NROW[i] = NROW[p]
            NROW[p] = NCOPY

        # Passo 6
        for j in range(i + 1, n):
            # Passo 7
            m = A[NROW[j]][i] / A[NROW[i]][i]
            # Passo 8
            for k in range(n + 1):
                A[NROW[j]][k] = A[NROW[j]][k] - m * A[NROW[i]][k]

    # Passo 9
    if A[NROW[n - 1]][n - 1] == 0:
        print("no unique solution exists")
        return None

    # Passo 10:
    x = [0.0] * n
    x[n - 1] = A[NROW[n - 1]][n] / A[NROW[n - 1]][n - 1]

    # Passo 11
    for i in range(n - 2, -1, -1):
        soma = sum(A[NROW[i]][j] * x[j] for j in range(i + 1, n))
        x[i] = (A[NROW[i]][n] - soma) / A[NROW[i]][i]

    # Passo 12:
    return x



def gaussian_elimination_scaled_partial_pivoting(n, A):
    """
    Resolve o sistema linear nxn usando Eliminação de Gauss com Pivoteamento Parcial Escalado.
    :param n: número de equações e incógnitas.
    :param A: matriz aumentada [A | b] de dimensão n x (n+1).
    """
    s = [0.0] * n
    NROW = [0] * n
    
    # Step 1
    for i in range(n):
        s[i] = max(abs(A[i][j]) for j in range(n)) 
        
        if s[i] == 0:
            print("no unique solution exists")
            return None
        
        NROW[i] = i
        
    # Step 2
    for i in range(n - 1):
        
        # Step 3
        p = i
        max_razao = abs(A[NROW[i]][i]) / s[NROW[i]]
        
        for j in range(i + 1, n):
            razao_atual = abs(A[NROW[j]][i]) / s[NROW[j]]
            if razao_atual > max_razao:
                max_razao = razao_atual
                p = j
        
        # Step 4
        if A[NROW[p]][i] == 0:
            print("no unique solution exists")
            return None
            
        # Step 5
        if NROW[i] != NROW[p]:
            NCOPY = NROW[i]
            NROW[i] = NROW[p]
            NROW[p] = NCOPY
            
        # Step 6
        for j in range(i + 1, n):
            # Step 7
            m = A[NROW[j]][i] / A[NROW[i]][i]
            # Step 8
            for k in range(n + 1):
                A[NROW[j]][k] = A[NROW[j]][k] - m * A[NROW[i]][k]
                
    # Step 9
    if A[NROW[n - 1]][n - 1] == 0:
        print("no unique solution exists")
        return None
        
    # Step 10
    x = [0.0] * n
    x[n - 1] = A[NROW[n - 1]][n] / A[NROW[n - 1]][n - 1]
    
    # Step 11
    for i in range(n - 2, -1, -1):
        soma = sum(A[NROW[i]][j] * x[j] for j in range(i + 1, n))
        x[i] = (A[NROW[i]][n] - soma) / A[NROW[i]][i]
        
    # Step 12
    return x

def lu_factorization(n, A):
    """
    Fatora a matriz A nxn no produto LU.
    :param n: dimensão da matriz.
    :param A: matriz de coeficientes n x n.
    """
    L = [[0.0] * n for _ in range(n)]
    U = [[0.0] * n for _ in range(n)]
    
    for i in range(n):
        L[i][i] = 1.0
        
    # Step 1
    U[0][0] = A[0][0] / L[0][0]
    
    if L[0][0] * U[0][0] == 0:
        print("Factorization impossible")
        return None, None
        
    # Step 2
    for j in range(1, n):
        U[0][j] = A[0][j] / L[0][0] 
        L[j][0] = A[j][0] / U[0][0] 
        
    # Step 3
    for i in range(1, n - 1):
        
        # Step 4
        soma_diag = sum(L[i][k] * U[k][i] for k in range(i))
        U[i][i] = A[i][i] - soma_diag
        
        if L[i][i] * U[i][i] == 0:
            print("Factorization impossible")
            return None, None
            
        # Step 5
        for j in range(i + 1, n):
            soma_u = sum(L[i][k] * U[k][j] for k in range(i))
            U[i][j] = (1.0 / L[i][i]) * (A[i][j] - soma_u)
            
            soma_l = sum(L[j][k] * U[k][i] for k in range(i))
            L[j][i] = (1.0 / U[i][i]) * (A[j][i] - soma_l)
            
    # Step 6
    soma_nn = sum(L[n - 1][k] * U[k][n - 1] for k in range(n - 1))
    U[n - 1][n - 1] = A[n - 1][n - 1] - soma_nn
    
    
    # Step 7
    return L, U

def solve_lu(n, L, U, b):
    """
    Resolve o sistema linear LUx = b.
    :param n: dimensão do sistema.
    :param L: matriz triangular inferior.
    :param U: matriz triangular superior.
    :param b: vetor de termos independentes.
    :return: vetor solução x.
    """
    # Passo 1: Resolver Ly = b 
    y = [0.0] * n
    for i in range(n):
        soma = sum(L[i][j] * y[j] for j in range(i))
        y[i] = (b[i] - soma) / L[i][i]
        
    # Passo 2: Resolver Ux = y 
    x = [0.0] * n
    for i in range(n - 1, -1, -1):
        soma = sum(U[i][j] * x[j] for j in range(i + 1, n))
        x[i] = (y[i] - soma) / U[i][i]
        
    return x

def ldlt_factorization(n, A):
    """
    Fatora uma matriz definida positiva A em L * D * L^T .
    :param n: dimensão da matriz A (n x n).
    :param A: matriz simétrica e definida positiva.
    :return: Uma tupla contendo lista de l[i][j] para j < i, lista com a diagonal D.
    """
    # Inicializa L
    L = [[1.0 if i == j else 0.0 for j in range(n)] for i in range(n)]

    # Inicializa D
    D = [0.0] * n

    # Passo 1
    for i in range(n):
        # Passo 2
        v = [0.0] * (i)
        for j in range(i):
            v[j] = L[i][j] * D[j]

        # Passo 3
        soma1 = sum(L[i][j] * v[j] for j in range(i))
        D[i] = A[i][i] - soma1

        # Passo 4
        for j in range(i + 1, n):
            soma2 = sum(L[j][k] * v[k] for k in range(i))
            L[j][i] = (A[j][i] - soma2) / D[i]

    return L, D

def solve_ldl(n, L, d, b):
    """
    Resolve o sistema linear LDL^Tx = b recebendo L como matriz 2D.
    """
    # Passo 1: Lz = b
    z = [0.0] * n
    for i in range(n):
        soma = sum(L[i][j] * z[j] for j in range(i))
        z[i] = b[i] - soma

    # Passo 2: Dy = z
    y = [0.0] * n
    for i in range(n):
        y[i] = z[i] / d[i]

    # Passo 3: L^T x = y
    x = [0.0] * n
    for i in range(n - 1, -1, -1):
        # L^T[i][j] é acessado como L[j][i]
        soma = sum(L[j][i] * x[j] for j in range(i + 1, n))
        x[i] = y[i] - soma

    return x

def cholesky(n, A):
    """
    Fatora uma matriz definida positiva A em L * L^T
    :param n: dimensão da matriz A (n x n).
    :param A: matriz simétrica e definida positiva.
    :return: Lista  com os elementos l[i][j] (para j <= i).
    """
    # Inicializa L
    L = [[0.0 for _ in range(n)] for _ in range(n)]

    # Passo 1
    if A[0][0] <= 0:
        print("Raiz Negativa")
        return None
    L[0][0] = A[0][0]**(1/2)

    # Passo 2
    for j in range(1, n):
        L[j][0] = A[j][0] / L[0][0]

    # Passo 3
    for i in range(1, n - 1):
        # Passo 4
        soma1 = sum(L[i][k] ** 2 for k in range(i))
        valor = A[i][i] - soma1
        if valor <= 0:
            print("Raiz Negativa.")
            return None
        L[i][i] = valor ** (1/2)

        # Passo 5
        for j in range(i + 1, n):
            soma2 = sum(L[j][k] * L[i][k] for k in range(i))
            L[j][i] = (A[j][i] - soma2) / L[i][i]

    # Passo 6
    soma3 = sum(L[n - 1][k] ** 2 for k in range(n - 1))
    valor2 = A[n - 1][n - 1] - soma3
    if valor2 <= 0:
        print("Raiz Negativa.")
        return None
    L[n - 1][n - 1] = valor2 ** (1/2)

    return L

def solve_cholesky(n, L, b):
    """
    Resolve o sistema linear LL^Tx = b recebendo L como matriz 2D.
    """
    # Passo 1: Ly = b
    y = [0.0] * n
    for i in range(n):
        soma = sum(L[i][j] * y[j] for j in range(i))
        y[i] = (b[i] - soma) / L[i][i]

    # Passo 2: L^T x = y
    x = [0.0] * n
    for i in range(n - 1, -1, -1):
        soma = sum(L[j][i] * x[j] for j in range(i + 1, n))
        x[i] = (y[i] - soma) / L[i][i]

    return x

def crout_tridiagonal(n, A, b):
    """
    Resolve o sistema linear tridiagonal usando a fatoração de Crout.
    :param n: dimensão do sistema.
    :param A: Matriz de coeficientes n x n (tridiagonal).
    :param b: vetor de termos independentes n x 1.
    :return: vetor solução x.
    """
    l_diag = [0.0] * n
    l_sub = [0.0] * n
    u_sup = [0.0] * n
    z = [0.0] * n
    x = [0.0] * n

    # Passo 1
    l_diag[0] = A[0][0]
    u_sup[0] = A[0][1] / l_diag[0]
    z[0] = b[0] / l_diag[0]

    # Passo 2
    for i in range(1, n - 1):
        l_sub[i] = A[i][i - 1]
        l_diag[i] = A[i][i] - l_sub[i] * u_sup[i - 1]
        u_sup[i] = A[i][i + 1] / l_diag[i]
        z[i] = (b[i] - l_sub[i] * z[i - 1]) / l_diag[i]

    # Passo 3
    l_sub[n - 1] = A[n - 1][n - 2]
    l_diag[n - 1] = A[n - 1][n - 1] - l_sub[n - 1] * u_sup[n - 2]
    z[n - 1] = (b[n - 1] - l_sub[n - 1] * z[n - 2]) / l_diag[n - 1]

    # Passo 4
    x[n - 1] = z[n - 1]

    # Passo 5
    for i in range(n - 2, -1, -1):
        x[i] = z[i] - u_sup[i] * x[i + 1]

    # Passo 6
    return x



