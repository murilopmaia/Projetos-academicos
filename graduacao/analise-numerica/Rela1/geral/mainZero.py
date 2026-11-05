import math
import sympy as sy


def addSufixo(fun: str) -> str:
    newFun = ""
    tam = len(fun)

    for l in range(tam):
        fun3 = fun[l:l+3]
        fun4 = fun[l:l+4]

        if fun3 == "sin" or \
            fun3 == "cos" or \
                fun4 == "sqrt":
            newFun += "math."
        newFun += fun[l]
    return newFun


def f(x: int|float) -> float|int:
    return eval(funcao.replace("x", str(x)))


def f_(x: int|float) -> float|int:
    return eval(funDer.replace("x", str(x)))


def bisse(erro: float, a: float, b: float) -> None:
    steps = -1
    fa = f(a)
    fb = f(b)
    
    with open(".\\ResultBisseccao.txt", "w") as arq:

        if fa * fb < 0:

            while True:
                steps += 1
                c: float = (b+a) / 2
                fc = f(c)

                arq.write(f"k = {steps} | a = {a} | b = {b} | f(a) = {fa} | f(b) = {fb} | b-a = {b-a} | c = {c} | f(c) = {fc}\n")

                if abs(fc) <= erro:
                    break
                elif fa * fc < 0:
                    b = c
                    fb = f(b)
                else:
                    a = c
                    fa = f(a)
        else:
            arq.write("\nResultado fora do escopo\n")


def posFake(erro: float, a: float, b: float) -> None:
    steps = -1
    fa = f(a)
    fb = f(b)
    
    with open(".\\ResultposFake.txt", "w") as arq:

        if fa * fb < 0:

            while True:
                steps += 1
                c: float = ((a*fb) - (b*fa)) / (fb-fa)
                fc = f(c)

                arq.write(f"k = {steps} | a = {a} | b = {b} | f(a) = {fa} | f(b) = {fb} | b-a = {b-a} | c = {c} | f(c) = {fc}\n")

                if abs(fc) <= erro:
                    break
                elif fa * fc < 0:
                    b = c
                    fb = f(b)
                else:
                    a = c
                    fa = f(a)
        else:
            arq.write("\nResultado fora do escopo\n")


def newtonRaphson(erro: float, a: float) -> None:
    x = a
    steps = -1

    with open(".\\ResultNR.txt", "w") as arq:

        while True:
            fx = f(x)
            f_x = f_(x)
            steps +=1

            arq.write(f"k = {steps} | x = {x} | f(x) = {fx} | f_(x) = {f_x}.  ->  ")

            x = (x - fx/f_x)

            arq.write(f"x = {x}\n")

            if abs(fx) <= erro:
                break


def secante(erro: float, a: float, b: float) -> None:
    x1 = a
    x2 = b
    steps = -1

    with open(".\\ResultSecante.txt", "w") as arq:

        while True:
            steps +=1

            fx1 = f(x1)
            fx2 = f(x2)

            x3 = (fx2*x1 - fx1*x2) / (fx2-fx1)
            fx3 = f(x3)

            arq.write(f"k = {steps} | x1 = {x1} | x2 = {x2}  ->  x3 = {x3} | f(x3) = {fx3}\n")

            x1 = x2
            x2 = x3

            if abs(fx3) <= erro:
                break


if __name__ == "__main__":
    with open(".\\fun.txt", "r") as arq:
        erro = float(arq.readline().replace("erro = ", ""))
        a = float(arq.readline().replace("a|x1 = ", ""))
        b = float(arq.readline().replace("b|x2 = ", ""))
        funcao = arq.readline().replace("funcao = ", "")
    
    derivada = sy.diff(funcao)
    funDer = addSufixo(str(derivada))

    funcao = addSufixo(funcao)

    bisse(erro, a, b)
   
    posFake(erro, a, b)
    
    newtonRaphson(erro, a)
     
    secante(erro, a, b)
    
