import sympy as sy
import sys


def f(fun, x: int|float) -> float|int:
    expr = sy.sympify(fun).subs('x', x)
    return sy.N(expr)

def trapezioMultiplo(fun, a, b, n):
    h = (b-a)/n
    vetX = []
    vetX.append(a)
    for i in range(1, n+1):
        vetX.append(vetX[i-1] + h)
    
    
    h = (vetX[-1] - vetX[0])
    somatorioFx1 = sum([f(fun, vetX[i]) for i in range(1, n)])
    f0 = f(fun, vetX[0])
    fn = f(fun, vetX[-1])

    I = h*(f0 + 2*somatorioFx1 + fn)/(2*n)
    return I
    

def main() -> None:
    with open(sys.argv[1], 'r') as arq:
        fun = arq.readline().strip().replace(" ", "").replace("fun=", "")
        a = float(arq.readline().strip().replace(" ", "").replace("a=", ""))
        b = float(arq.readline().strip().replace(" ", "").replace("b=", ""))
        n = int(arq.readline().strip().replace(" ", "").replace("n=", ""))
        
    result = trapezioMultiplo(fun, a, b, n)

    with open(sys.argv[2], 'w') as arq:
        arq.write(f'Integral = {result}\n')
if __name__ == '__main__':
    main()