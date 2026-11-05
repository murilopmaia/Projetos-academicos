import sympy as sy
import sys

def f(fun, x: int|float) -> float|int:
    expr = sy.sympify(fun).subs('x', x)
    return sy.N(expr)

def simpson38(fun, a, b):
    h = (b-a)/3
    vetX = []
    vetX.append(a)
    for i in range(1, 4):
        vetX.append(vetX[i-1]+h)

    n = len(vetX)
    h = vetX[-1] - vetX[0]
    fn = [f(fun, vetX[i]) for i in range(n)]
    I = h*(fn[0] + 3*fn[1] + 3*fn[2] + fn[3])/(8)
    return I

def main() -> None:
    with open(sys.argv[1], 'r') as arq:
        fun = arq.readline().strip().replace(" ", "").replace("fun=", "")
        a = float(arq.readline().strip().replace(" ", "").replace("a=", ""))
        b = float(arq.readline().strip().replace(" ", "").replace("b=", ""))
        
    result = simpson38(fun, a, b)

    with open(sys.argv[2], 'w') as arq:
        arq.write(f'Integral = {result}')

if __name__ == '__main__':
    main()