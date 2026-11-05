import sys
import sympy as sy

def f(fun, x: int|float) -> float|int:
    expr = sy.sympify(fun).subs('x', x)
    return sy.N(expr)

def quadraduraGauss(fun, a, b, p):
    ordem = {
        '2':[
            [1.0, 1.0],
            [-0.577350269, 0.577350269]
        ],
        '3':[
            [0.5555556, 0.8888889, 0.5555556],
            [-0.774596669, 0.0, 0.774596669]
        ],
        '4':[
            [0.3478548, 0.6521452, 0.6521452, 0.3478548],
            [-0.861136312, -0.339981044, 0.339981044, 0.861136312]
        ],
        '5':[
            [0.2369269, 0.4786287, 0.5688889, 0.4786287, 0.2369269],
            [-0.906179846, -0.538469310, 0.0, 0.538469310, 0.906179846]
        ]
    }

    # Mudança de variáveis
    x = f'(({b} + {a}) + ({b} - {a})*x)/2'
    dx = (b-a)/2

    expr = sy.sympify(x)
    expressao_expandida = '(' + str(sy.expand(expr)) + ')'
    expr = sy.sympify(fun).subs('x', expressao_expandida)
    fun = '(' + str(expr) + f') * {dx}'
    
    # Aplicando
    pesos = ordem[p][0]
    argsFun = ordem[p][1]
    n = len(pesos)

    I = sum([pesos[i] * f(fun, argsFun[i]) for i in range(n)])
    
    return I


def main():
    with open(sys.argv[1] , 'r') as arq:
        fun = arq.readline().strip().replace(" ", "").replace("fun=", "")
        a = float(arq.readline().strip().replace(" ", "").replace("a=", ""))
        b = float(arq.readline().strip().replace(" ", "").replace("b=", ""))
        p = arq.readline().strip().replace(" ", "").replace("p=", "")
    
    result = quadraduraGauss(fun, a, b, p)

    with open(sys.argv[2], 'w') as arq:
        arq.write(f'Integral = {result}')

if __name__ == '__main__':
    main()