import sympy as sy
import sys

def f(fun: str, x: int|float, var: str, y: int|float = 0) -> float|int:
    expr = sy.sympify(fun).subs('x', x).subs(var, y)
    return sy.N(expr)

def ordem3(fun: str, var: str, yi: float, a: float, b: float, h: float):
    var = var.replace("'", "")
    n = int((b-a)//h)
    xi = a
    result = [[xi, yi]]
    for i in range(0, n):
        k1 = f(fun, xi, var, yi)
        k2 = f(fun, xi + (1/2)*h, var, yi + (1/2)*h*k1)
        k3 = f(fun, xi + h, var, yi - k1*h + 2*k2*h)
        yi = yi + (1/6)*(k1 + 4*k2 + k3)*h
        xi += h
        result.append([xi, yi])
    return result

def main():
    with open(sys.argv[1], 'r') as arq:
        var, fun = arq.readline().strip().replace(' ', '').split('=')
        a, b = [float(x) for x in arq.readline().strip().replace(' ', '').split(',')]
        yi = float(arq.readline().strip().replace(' ', ''))
        h = float(arq.readline().strip().replace(' ', ''))

    result = ordem3(fun, var, yi, a, b, h)

    with open(sys.argv[2], 'w') as arq:
        for res in result:
            
            arq.write(f'{res[0]} | {res[1]}\n')
        
if __name__ == '__main__':
    main()