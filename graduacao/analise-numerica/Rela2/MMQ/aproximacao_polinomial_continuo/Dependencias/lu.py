import sympy as sy
import sys

A: list[list[float]] = []
x: list[list] = []
B: list[float] = []


def pivoteamento(A, B):
    n = len(A)
    for i in range(n):
        pivo_id = i
        for k in range(0, n):
            if abs(A[k][i]) > abs(A[pivo_id][i]):
                pivo_id = k
                
        A[i], A[pivo_id] = A[pivo_id].copy(), A[i].copy()
        B[i], B[pivo_id] = B[pivo_id], B[i]

def XToY(x: list[list[str]]):
    y = []
    for t in x:
        y.append([t[0].replace("x", "y"), t[0].replace("x", "y")])
    
    return y

def incializandoU(tam: int):
    U: list[list] = []

    for i in range(tam):
        U.append([])
        for j in range(tam):
            U[i].append(0)

    return U

def incializandoL(tam: int):
    L: list[list] = []

    for i in range(tam):
        L.append([])
        for j in range(tam):
            if i == j:
                L[i].append(1)
            else:
                L[i].append(0)
    return L

def LU(A, B, x):
    x = [[x, x] for x in x]
    tam = len(A)
    # definindo U e L
    U: list[list] = incializandoU(tam)
    L: list[list] = incializandoL(tam)

    # u1j = a1j
    U[0] = A[0].copy()

    # li1 = ai1/a11
    for i in range(tam):
        L[i][0] = A[i][0]/A[0][0]

    for i in range(1, tam):
        for j in range(1, i):
            sum = 0
            for k in range(0, j):
                sum += L[i][k]*U[k][j]
            L[i][j] = (A[i][j] - sum) / U[j][j]
            
        for j in range(i, tam):
            sum = 0
            for k in range(0, i):
                sum += L[i][k]*U[k][j]
            U[i][j] = A[i][j] - sum
            
    # L * y = B
    y = XToY(x)
    for i in range(tam):
        sum = ""
        for j in range(0, tam):
            sum += f"{L[i][j]} * {y[j][1]} +"

        a = sy.Symbol(y[i][1])
        y[i][1] = sy.solve(sum + f"- {B[i]}", a)[0]

    # U * X = Y
    for i in range(tam-1, -1, -1):
        sum = ""
        for j in range(0, tam):
            sum += f"{U[i][j]} * {x[j][1]} +"

        a = sy.Symbol(x[i][1])
        x[i][1] = sy.solve(sum + f"- {y[i][1]}", a)[0]


    return x
