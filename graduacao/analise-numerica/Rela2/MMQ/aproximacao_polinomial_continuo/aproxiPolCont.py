import sys
from Dependencias.lu import LU
from Dependencias.gauss import quadraduraGauss

def aproxiPolCont(fun, a, b, grau) -> None:

    GrauPol = grau + 1
    mat: list[list] = []
    vet: list = []
    vetA: list = []

    for i in range(GrauPol):
        mat.append([])
        vet.append(quadraduraGauss('(' +fun + ')' + f'*(x**{i})', a, b, '5'))
        vetA.append(f'a{i}')
        for j in range(GrauPol):
            mat[i].append(quadraduraGauss(f'(x**{j})*(x**{i})', a, b, '5'))

    result = LU(mat, vet, vetA)
    
    return result


def main() -> None:
    vetX: list
    vetY: list

    with open(sys.argv[1], 'r') as arq:
        fun = arq.readline().strip().replace(" ", "").replace("fun=", "")
        a = float(arq.readline().strip().replace(" ", "").replace("a=", ""))
        b = float(arq.readline().strip().replace(" ", "").replace("b=", ""))
        grau = int(arq.readline().strip().replace(" ", "").replace("grau=", ""))
        
        

    result = aproxiPolCont(fun, a, b, grau)
    

    with open(sys.argv[2], 'w') as arq:
        expr = f'f(x) = {result[0][1]}'
        n = len(result)
        for i in range(1, n):
            if result[i][1] >= 0:
                expr += f' + {result[i][1]}*x**{i}'
            else:
                expr += f' {result[i][1]}*x**{i}'

        arq.write(expr)

if __name__ == "__main__":
    main()