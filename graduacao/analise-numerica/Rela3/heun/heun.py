import sys
import sympy as sy

def f(fun: str, x: int|float, var: str, y: int|float = 0) -> float|int:
    expr = sy.sympify(fun).subs('x', x).subs(var, y)
    return sy.N(expr)


def heun(fun: str, var: str, yi: float, a: float, b: float, h: float) -> list:
    var = var.replace("'", "")
    n = int((b-a)/h)
    xi = a
    result = [[xi, yi]]
    for i in range(0, n):
        y0i = yi + f(fun, xi, var, yi) * h
        yi = yi + ((f(fun, xi, var, yi) + f(fun, xi + h, var, y0i))/2) * h
        xi += h
        result.append([xi, yi])
    return result
    
def main():
    with open(sys.argv[1], 'r') as arq:
        var, fun = arq.readline().strip().replace(' ', '').split('=')
        a, b = [float(x) for x in arq.readline().strip().replace(' ', '').split(',')]
        yi = float(arq.readline().strip().replace(' ', ''))
        h = float(arq.readline().strip().replace(' ', ''))

    result = heun(fun, var, yi, a, b, h)

    with open(sys.argv[2], 'w') as arq:
        for res in result:
            arq.write(f'{res[0]} | {res[1]}\n')
        

if __name__ == '__main__':
    main()