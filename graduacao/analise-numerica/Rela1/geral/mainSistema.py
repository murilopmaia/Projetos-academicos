import sympy as sy
import math

A: list[list[float]] = []
x: list[list] = []
B: list[float] = []

def deepCopyMat(mat: list[list]):
    matCopy = []
    for vet in mat:
        matCopy.append(vet.copy())

    return matCopy

def XToY(x: list[list[str]]):
    y = []
    for t in x:
        y.append([t[0].replace("x", "y"), t[0].replace("x", "y")])
    
    return y

def processandoSistema(fun: str, j):
    A.append([])
 
    fun = fun.replace(" ", "")

    strVar = ""
    strNum = ""
    change = 0
    fim = False

    for i in range(len(fun)):
        
        if fun[i] == "*" or fun[i] == "+" or fun[i] == "-":
            change = 0 if change == 1 else 1
        elif fun[i] == "=":
            change = 0 if change == 1 else 1
            B.append(float(fun[i+1:]))
            fim = True

        if change == 0:
            if strVar != "" and j == 0:
                x.append([strVar.replace("*", ""), strVar.replace("*", "")])
            strVar = ""
            strNum += fun[i]
        else:
            if strNum != "":
                A[j].append(float(strNum))
            strNum = ""
            strVar += fun[i]

        if fim == True:
            break

def gauss():

    Ac = deepCopyMat(A)
    Bc = B.copy()
    xc = deepCopyMat(x)
    tam = len(Ac)
    
    for i in range(0, tam-1):
        for j in range(i+1, tam):
            m = Ac[j][i]/Ac[i][i]
            for z in range(0, tam):
                Ac[j][z] = Ac[j][z] - m*Ac[i][z]
            Bc[j] = Bc[j] - m*Bc[i]

    for i in range(tam-1, -1, -1):
        sum = ""
        for j in range(0, tam):
            sum += f"{Ac[i][j]} * {xc[j][1]} +"

        a = sy.Symbol(xc[i][1])
        xc[i][1] = sy.solve(sum + f"- {Bc[i]}", a)[0]

    with open(".\\ResultGauss.txt", "w") as arq:
        for i in range(len(x)):
            arq.write(f"{xc[i][0]} = {xc[i][1]}\n")

def incializandoU(tam: int):
    U: list[list] = []

    for i in range(tam):
        U.append([])
        for j in range(tam):
            U[i].append(0)

    return U

def incializandoL(tam: int):
    L: list[list] = []

    for i in range(tam):
        L.append([])
        for j in range(tam):
            if i == j:
                L[i].append(1)
            else:
                L[i].append(0)
    return L

def LU():
    
    Ac: list[list] = deepCopyMat(A)
    Bc: list = B.copy()
    xc: list[list] = deepCopyMat(x)
    tam = len(Ac)

    # definindo U e L
    U: list[list] = incializandoU(tam)
    L: list[list] = incializandoL(tam)

    # u1j = a1j
    U[0] = Ac[0].copy()

    # li1 = ai1/a11
    for i in range(tam):
        L[i][0] = Ac[i][0]/Ac[0][0]

    for i in range(1, tam):
        for j in range(1, i):
            sum = 0
            for k in range(0, j):
                sum += L[i][k]*U[k][j]
            L[i][j] = (Ac[i][j] - sum) / U[j][j]
            

        for j in range(i, tam):

            sum = 0
            for k in range(0, i):
                sum += L[i][k]*U[k][j]
            U[i][j] = Ac[i][j] - sum
            
    # L * y = B
            
    y = XToY(xc)
    for i in range(tam):
        sum = ""
        for j in range(0, tam):
            sum += f"{L[i][j]} * {y[j][1]} +"

        a = sy.Symbol(y[i][1])
        y[i][1] = sy.solve(sum + f"- {Bc[i]}", a)[0]

    # U * X = Y
    
    for i in range(tam-1, -1, -1):
        sum = ""
        for j in range(0, tam):
            sum += f"{U[i][j]} * {xc[j][1]} +"

        a = sy.Symbol(xc[i][1])
        xc[i][1] = sy.solve(sum + f"- {y[i][1]}", a)[0]


    with open(".\\ResultLU.txt", "w") as arq:
        arq.write("U:\n")
        for linha in U:
            arq.write("[")
            for ele in linha:
                arq.write(f"{ele:.5f}". center(10))
            arq.write("]\n")

        arq.write("\nL:\n")
        for linha in L:
            arq.write("[")
            for ele in linha:
                arq.write(f"{ele:.5f}".center(10))
            arq.write("]\n")

        
        for linha in y:
            arq.write(f"\n{linha[0]} = {linha[1]:.5f}")
        
        arq.write("\n")
        for linha in xc:
            arq.write(f"\n{linha[0]} = {linha[1]:.5f}")

def tamanhoVetor(xold: list[list], xnew: list[list]):
    vet = []
    tam = 0

    for a, b in zip(xold, xnew):
        vet.append(b[1]-a[1])

    for i in vet:
        tam += i**2
    
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
        xold[i][1] = 0

    # resolvendo
    with open(".\\ResultMetodoJacobi.txt", "w") as arq:
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
                arq.write(f"{xnew[i][1]:.4f}\n")
            
            arq.write("\n")
            cont+=1
            if tamanhoVetor(xold, xnew) <= 0.001:
                break

def metodoGaussSeidel(): 
    
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
        xold[i][1] = 0

    # resolvendo
    with open(".\\ResultMetodoGaussSeidel.txt", "w") as arq:
        cont = 1
        while True:
            xold = deepCopyMat(xnew)
            
            arq.write(f"x({cont}):\n")

            for i in range(tam):
                equa = esquacoes[i]
                for j in range(tam):
                    if i != j:
                        equa = equa.replace(xnew[j][0], str(xnew[j][1]))
                
                a = sy.Symbol(xnew[i][0])
                xnew[i][1] = sy.solve(equa, a)[0]
                arq.write(f"{xnew[i][1]:.5f}\n")
            
            arq.write("\n")
            cont+=1
            if tamanhoVetor(xold, xnew) <= 0.001:
                break
    
        
if __name__ == "__main__":
    with open(".\\sis.txt", "r") as arq:
        j = 0
        fun = arq.readline()
        while fun != "":
            processandoSistema(fun, j)
            fun = arq.readline()
            j+=1

    gauss()

    LU()

    metodoJacobi()

    metodoGaussSeidel()

    