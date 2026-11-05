import sympy as sy
from Dependencias import lu
import sys

def iniZero(n: int, m: int|None = None):
    mat = []
    if m != None:
        for i in range(n):
            mat.append([0] * m)
    else:
        mat = [0] * n
    return mat

def f(fun: str, h: int|float, x: float|int) -> float|int:
    expr = sy.sympify(fun).subs('h', h).subs('x', x)
    return sy.N(expr)

def diferencas_finitas(fun1: str, fun2: str, ini: float, fim: float, a: float, b: float, h: float):
    n = int((b - a) / h)
    
    A = iniZero(n-1, n-1)
    B = iniZero(n-1)
    x = [f'x{i}' for i in range(1, n)]
    xi = a
    for i in range(1, n):
        if i == 1:
            A[i-1][i-1] = f(fun1, h, xi)
            A[i-1][i] = -1
            B[i-1] = f(fun2, h, xi) + ini
        elif i == n-1:
            A[i-1][i-2] = -1
            A[i-1][i-1] = f(fun1, h, xi)
            B[i-1] = f(fun2, h, xi) + fim
        else:
            A[i-1][i-2] = -1
            A[i-1][i-1] = f(fun1, h, xi)
            A[i-1][i] = -1
            B[i-1] = f(fun2, h, xi)
        xi += h
    result = lu.LU(A, B, x)
    
    res = [[a, ini]]
    xi = a + h
    for i in range(0, n-1):
        res.append([xi, result[i][1]])
        xi += h
    res.append([b, fim])
    return res
    

def main():
    with open(sys.argv[1], 'r') as arq:
        fun1, fun2 = arq.readline().strip().replace(' ', '').split(',')
        ini, fim = [float(x) for x in arq.readline().strip().replace(' ', '').split(',')]
        a, b = [float(x) for x in arq.readline().strip().replace(' ', '').split(',')]
        h = float(arq.readline().strip().replace(' ', ''))

    result = diferencas_finitas(fun1, fun2, ini, fim, a, b, h)

    with open(sys.argv[2], 'w') as arq:
        for res in result:
            
            arq.write(f'{res[0]} | {res[1]}\n')
        
if __name__ == '__main__':
    main()
