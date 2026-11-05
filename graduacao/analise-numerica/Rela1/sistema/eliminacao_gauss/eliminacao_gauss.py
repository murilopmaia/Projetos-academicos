import sympy as sy
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



def pivoteamento():
    n = len(A)
    for i in range(n):
        pivo_id = i
        for k in range(0, n):
            if abs(A[k][i]) > abs(A[pivo_id][i]):
                pivo_id = k
                
        A[i], A[pivo_id] = A[pivo_id].copy(), A[i].copy()
        B[i], B[pivo_id] = B[pivo_id], B[i]

def gauss():
    tam = len(A)
    
    for i in range(0, tam-1):
        for j in range(i+1, tam):
            m = A[j][i]/A[i][i]
            for z in range(0, tam):
                A[j][z] = A[j][z] - m*A[i][z]
            B[j] = B[j] - m*B[i]

    for i in range(tam-1, -1, -1):
        sum = ""
        for j in range(0, tam):
            sum += f"{A[i][j]} * {x[j][1]} +"

        a = sy.Symbol(x[i][1])
        x[i][1] = sy.solve(sum + f"- {B[i]}", a)[0]

    

    with open(sys.argv[2], "w") as arq:
        for linha in range(len(A)):
            arq.write("[")
            for ele in A[linha]:
                arq.write(f"{ele:.5f}". center(10))
            arq.write("]")
            arq.write(f" [{x[linha][0]}] ")
            arq.write(f"[{B[linha]: .5f}]".center(10))
            arq.write("\n")
        arq.write("\n")
        for i in range(len(x)):
            arq.write(f"{x[i][0]} = {x[i][1]}\n")


if __name__ == "__main__":
    with open(sys.argv[1], "r") as arq:
        j = 0
        fun = arq.readline()
        while fun != "":
            processandoSistema(fun, j)
            fun = arq.readline()
            j+=1
    
    pivoteamento()
    gauss()
    

    