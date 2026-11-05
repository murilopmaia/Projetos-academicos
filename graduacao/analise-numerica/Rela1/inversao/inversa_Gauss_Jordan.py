import sys

A: list[list[float]] = []
x: list[list] = []
B: list[float] = []

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

def printMatArq(mat: list[list], id: list[list], arq):
    tam = len(mat)

    for i in range(tam):
        arq.write("\n[")
        for j in range(tam):
            arq.write(f"  {mat[i][j]: .6f}  ".center(10))
        arq.write("|")
        for j in range(tam):
            arq.write(f"  {id[i][j]: .6f}  ".center(10))
        arq.write("]")

def deepCopy(mat: list[list]):
    c = []
    for linha in mat:
        c.append(linha.copy())
    return c

def identidade(tam: int):
    iden: list[list] = []
    for i in range(tam):
        iden.append([])
        for j in range(tam):
            if i == j:
                iden[i].append(1)
            else:
                iden[i].append(0)
    return iden

def normaInfinita(mat: list[list]) -> float|int:
    max_soma_linha = max(sum(abs(x) for x in linha) for linha in mat)
    return max_soma_linha
            
def numeroConMat(Ac: list[list], inv: list[list]) -> float|int:
    return normaInfinita(Ac) * normaInfinita(inv)
   
    
def inversaoGauss(): 
    tam = len(A)
    Acopy = deepCopy(A)
    id: list[list] = identidade(tam)
    
    with open(sys.argv[2], "w") as arq:
        printMatArq(A,id, arq)
        arq.write("\n")
        arq.write("-"*50)

        for j in range(tam):
            pivo = A[j][j]
            for z in range(tam):
                A[j][z] = A[j][z]/pivo
                id[j][z] = id[j][z]/pivo

            for z in range(tam):
                if z == j:
                    continue
                else:
                    m = A[z][j]
                    for k in range(tam):
                        A[z][k] -= m*A[j][k]
                        id[z][k] -= m*id[j][k]


            printMatArq(A, id, arq)
            arq.write("\n")
            arq.write("-"*50)
        
        
        arq.write(f"\n\nNorma infinita do sistema = {normaInfinita(Acopy)}\n")
        arq.write(f"Norma infinita da inversa = {normaInfinita(id)}\n")
        arq.write(f"Numero de condicao da matriz = {numeroConMat(Acopy, id)}\n\n")

        for i in range(tam):
            result = 0
            for j in range(tam):
                result += id[i][j] * B[j]
            arq.write(f"{x[i][0]} = {result}\n")

if __name__ == "__main__":
    with open(sys.argv[1], "r") as arq:
        j = 0
        fun = arq.readline()
        while fun != "":
            processandoSistema(fun, j)
            fun = arq.readline()
            j+=1

    inversaoGauss()


    