import sys
from Dependencias.lu import LU

def produtoEscalar(vet1, vet2) -> int:
    return sum([vet1[i]*vet2[i] for i in range(len(vet1))])

def aproxiPolDisc(vetX, vetY) -> None:
    nX = len(vetX)
    nY = len(vetY)
    if nX != nY:
        raise Exception("Vetores com tamanhos diferentes")

    u: list[list] = []
    GrauPol = nX - 1
    mat: list[list] = []
    vet: list = []
    vetA: list = []

    for i in range(GrauPol):
        u.append([x**i for x in vetX])

    for i in range(GrauPol):
        mat.append([])
        vet.append(produtoEscalar(vetY, u[i]))
        vetA.append(f'a{i}')
        for j in range(GrauPol):
            mat[i].append(produtoEscalar(u[i], u[j]))


    result = LU(mat, vet, vetA)
    return result
    


def main() -> None:
    vetX: list
    vetY: list

    with open(sys.argv[1], 'r') as arq:
        vetX = arq.readline().strip().replace(" ", "").split(",")
        vetX = [float(x) for x in vetX]
        vetY = arq.readline().strip().replace(" ", "").split(",")
        vetY = [float(y) for y in vetY]
    
    result = aproxiPolDisc(vetX, vetY)

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