import sys


def regressao_linear(vetX: list, vetY: list) -> None:

    # Verificar sem vetX e vetY possuem o mesmo tamanho
    nX = len(vetX)
    nY = len(vetY)
    if nX != nY:
        raise Exception("Vetores com tamanhos diferentes")
    n = nX
    
    somaXiYi = sum([vetY[i]*vetX[i] for i in range(n)])
    somaXi = sum(vetX)
    somaYi = sum(vetY)
    somaXi2 = sum([x**2 for x in vetX])
    x_ = somaXi/n
    y_ = somaYi/n

    a1 = (n*somaXiYi - somaXi*somaYi)/(n*somaXi2 - somaXi**2)
    a0 = y_ -  a1*x_

    sr = sum([(vetY[i] - a0 - a1*vetX[i])**2 for i in range(n)])
    st = sum([(vetY[i] - y_)**2 for i in range(n)])
    
    syx = (sr/(7-2))**(1/2)
    r2 = (st - sr)/st
    r = r2**(1/2)

    return [a0, a1, syx, r2, r]


def main() -> None:
    vetX: list
    vetY: list

    with open(sys.argv[1], 'r') as arq:
        vetX = arq.readline().strip().replace(" ", "").split(",")
        vetX = [float(x) for x in vetX]
        vetY = arq.readline().strip().replace(" ", "").split(",")
        vetY = [float(y) for y in vetY]

    
    a0, a1, syx, r2, r = regressao_linear(vetX, vetY)

    with open(sys.argv[2], 'w') as arq:
        if a1 >= 0:
            arq.write(f'y = {a0} + {a1}*x\n')
        else:
            arq.write(f'y = {a0} {a1}*x\n')
        arq.write(f'"Desvio padrao" = {syx}\n')
        arq.write(f'Coeficiente de determinacao = {r2}\n')
        arq.write(f'Coeficiente de Correlacao = {r}')
        
        

if __name__ == "__main__":
    main()