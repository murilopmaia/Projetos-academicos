import sympy as sy
import sys


def f(fun, x: int|float) -> float|int:
    expr = sy.sympify(fun).subs('x', x)
    return sy.N(expr)

def trapezioSimples(fun, a, b):
    h = (b-a)
    f0 = f(fun, a)
    fb = f(fun, b)

    I = h*(f0 + fb)/2
    return I
    

def main() -> None:
    with open(sys.argv[1], 'r') as arq:
        fun = arq.readline().strip().replace(" ", "").replace("fun=", "")
        a = float(arq.readline().strip().replace(" ", "").replace("a=", ""))
        b = float(arq.readline().strip().replace(" ", "").replace("b=", ""))
        
        
    result = trapezioSimples(fun, a, b)

    with open(sys.argv[2], 'w') as arq:
        arq.write(f'Integral = {result}\n')

if __name__ == '__main__':
    main()