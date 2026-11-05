import sympy as sy
import math
import sys

A: list[list[float]] = []
x: list[list] = []
B: list[float] = []

def deepCopyMat(mat: list[list]):
    matCopy = []
    for vet in mat:
        matCopy.append(vet.copy())

    return matCopy

def processandoSistema(fun: str, j):
    A.append([])
 
    fun = fun.replace(" ", "")

    strVar = ""
    strNum = ""
    change = 0
    fim = True
    i = 0

    while fim:
        
        if fun[i] in "-+":
            change = 0
        elif fun[i] == '*':
            change = 1
            i+=1
        elif not fun[i].isdigit() and (fun[i] not in '-+.='):
            change = 1
        elif fun[i] == "=":
            change = 0
            B.append(float(fun[i+1:]))
            fim = False

        if change == 0:
            if strVar != "" and j == 0:
                x.append([strVar, strVar])
            strVar = ""
            strNum += fun[i]
        else:
            if strNum == "+" or strNum == '-' or i == 0:
                strNum += '1'
                A[j].append(float(strNum))
            elif strNum != "":
                A[j].append(float(strNum))

            strNum = ""
            strVar += fun[i]
        i+=1

def pivoteamento():
    n = len(A)
    for i in range(n):
        pivo_id = i
        for k in range(0, n):
            if abs(A[k][i]) > abs(A[pivo_id][i]):
                pivo_id = k
                
        A[i], A[pivo_id] = A[pivo_id].copy(), A[i].copy()
        B[i], B[pivo_id] = B[pivo_id], B[i]

def tamanhoVetor(xold: list[list], xnew: list[list]):
    tam = 0
    for a, b in zip(xold, xnew):
        tam += (b[1]-a[1])**2

    tam = math.sqrt(tam)
    return tam

def metodoJacobi():
    # incializando
    esquacoes: list[str] = []
    xold = deepCopyMat(x)
    xnew = deepCopyMat(x)
    tam = len(A)

    # remodelando em equações e inicializando x
    for i in range(tam):
        equa = ""
        for j in range(tam):
            equa += f"{A[i][j]}*{x[j][1]} + "
        equa += f"-{B[i]}"
        esquacoes.append(equa)

        xnew[i][1] = 0

    # resolvendo
    with open(sys.argv[2], "w") as arq:
        cont = 1
        while True:
            xold = deepCopyMat(xnew)
            
            arq.write(f"x({cont}):\n")

            for i in range(tam):
                equa = esquacoes[i]
                for j in range(tam):
                    if i != j:
                        equa = equa.replace(xold[j][0], str(xold[j][1]))
                
                a = sy.Symbol(xold[i][0])
                xnew[i][1] = sy.solve(equa, a)[0]
                arq.write(f"{xnew[i][0]} = {xnew[i][1]} | ")
            
            arq.write("\n\n")
            cont+=1
            if tamanhoVetor(xold, xnew) <= 0.0001:
                break


if __name__ == "__main__":
    with open(sys.argv[1], "r") as arq:
        j = 0
        fun = arq.readline()
        while fun != "":
            processandoSistema(fun, j)
            fun = arq.readline()
            j+=1

    pivoteamento()
    metodoJacobi()

   