import sys
import sympy as sy

def lagrange(vetX, vetY):
    nX = len(vetX)
    nY = len(vetY)
    if nX != nY:
        raise Exception("Vetores com tamanhos diferentes")
    n = nX

    P: str = ''

    for i in range(n):
        result = 1
        expr = ''
        for j in range(n):
            if i != j:
                expr += f'(x-{vetX[j]})*'
                result *= (vetX[i] - vetX[j])
        result = 1/result
        expr += f'{result}'
        P += f'(({expr})*{vetY[i]}) +'
        
    P += '0'

    expr = sy.sympify(P)
    expressao_simplficada = sy.expand(expr)

    return str(expressao_simplficada)

def main() -> None:
    vetX: list
    vetY: list

    with open(sys.argv[1], 'r') as arq:
        vetX = arq.readline().strip().replace(" ", "").split(",")
        vetX = [float(x) for x in vetX]
        vetY = arq.readline().strip().replace(" ", "").split(",")
        vetY = [float(y) for y in vetY]

    result = lagrange(vetX, vetY)

    with open(sys.argv[2], 'w') as arq:
        arq.write('f(x) = ' + result)

if __name__ == '__main__':
    main()