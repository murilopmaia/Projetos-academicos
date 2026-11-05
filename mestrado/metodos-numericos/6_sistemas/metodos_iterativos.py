import numpy as np


def jacobi_iterative(n, A, b, XO, TOL, N):
    """
    Resolve Ax = B a partir de uma aproximação inicial x^(0) utilizando o método Jacobi.
    :param n: número de equações e incógnitas.
    :param A: matriz de coeficientes n x n.
    :param b: vetor de termos independentes n x 1.
    :param XO: aproximação inicial x^(0).
    :param TOL: tolerância para o critério de parada.
    :param N: número máximo de iterações permitidas.
    :return: vetor de aproximação x ou None em caso de falha.
    """
    # Passo 1
    k = 1
    x = [0.0] * n

    # Passo 2
    while k <= N:
        # Passo 3
        for i in range(n):
            soma = sum(A[i][j] * XO[j] for j in range(n) if j != i)

            x[i] = (1 / A[i][i]) * (-soma + b[i])

        # Passo 4
        norma = max(abs(x[i] - XO[i]) for i in range(n))
        if norma < TOL:
            return x, k

        # Passo 5
        k += 1

        # Passo 6
        for i in range(n):
            XO[i] = x[i]

    # Passo 7
    print("Maximum number of iterations exceeded")
    return None, k

def gauss_seidel_iterative(n, A, b, XO, TOL, N):
    """
    Resolve Ax = b a partir de uma aproximação inicial x^(0).
    """
    x = [0.0] * n
    
    # Step 1 
    k = 1
    
    # Step 2 
    while k <= N:
        
        # Step 3 
        for i in range(n):
            soma1 = sum(A[i][j] * x[j] for j in range(i))
            soma2 = sum(A[i][j] * XO[j] for j in range(i + 1, n))
            
            x[i] = (1.0 / A[i][i]) * (-soma1 - soma2 + b[i])
            
        # Step 4 
        erro = max(abs(x[i] - XO[i]) for i in range(n))
        if erro < TOL:
            return x, k 
            
        # Step 5 
        k += 1
        
        # Step 6 
        for i in range(n):
            XO[i] = x[i]
            
    # Step 7 
    print("Maximum number of iterations exceeded")
    return None, k

def sor_iterative(n, A, b, XO, omega, TOL, N):
    """
    Aproxima a solução do sistema Ax = b usando o método iterativo SOR.
    :param n: número de equações e incógnitas.
    :param A: matriz de coeficientes n x n.
    :param b: vetor de termos independentes n x 1.
    :param XO: aproximação inicial x^(0).
    :param omega: parâmetro de relaxação (w).
    :param TOL: tolerância para o critério de parada.
    :param N: número máximo de iterações permitidas.
    :return: vetor de aproximação x ou None em caso de falha.
    """
    # Passo 1
    k = 1
    x = [0.0] * n

    # Passo 2
    while k <= N:
        # Passo 3
        for i in range(n):
            soma1 = sum(A[i][j] * x[j] for j in range(i))
            soma2 = sum(A[i][j] * XO[j] for j in range(i + 1, n))

            x[i] = (1 - omega) * XO[i] + (1 / A[i][i]) * (omega * (-soma1 - soma2 + b[i]))

        # Passo 4: 
        norma = max(abs(x[i] - XO[i]) for i in range(n))
        if norma < TOL:
            return x, k

        # Passo 5
        k += 1

        # Passo 6
        for i in range(n):
            XO[i] = x[i]

    # Passo 7
    print("Maximum number of iterations exceeded")
    return None, k





