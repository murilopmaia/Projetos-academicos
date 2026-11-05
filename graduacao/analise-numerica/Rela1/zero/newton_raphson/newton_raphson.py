import sympy as sy
import sys


def f(x: int|float) -> float|int:
    
    expr = sy.sympify(funcao).subs('x', x)
    return sy.N(expr)


def f_(x: int|float) -> float|int:

    expr = sy.sympify(funDer).subs('x', x)
    return sy.N(expr)
    

def newtonRaphson(erro: float, a: float) -> None:
    x = a
    steps = -1

    with open(sys.argv[2], "w") as arq:

        while True:
            fx = f(x)
            f_x = f_(x)
            steps +=1

            arq.write(f"k = {steps} | x = {x: .6f} | f(x) = {fx: .6f} | f_(x) = {f_x : .6f}.  ->  ")

            x = (x - fx/f_x)

            arq.write(f"x = {x}\n")

            if abs(fx) <= erro:
                break

if __name__ == "__main__":

    arqFile = sys.argv[1]

    with open(arqFile, "r") as arq:
        erro = float(arq.readline().replace(" ", "").replace("erro=", ""))
        a = float(arq.readline().replace(" ", "").replace("x1=", ""))
        funcao = arq.readline().replace(" ", "").replace("funcao=", "")
    
    
    funDer = str(sy.diff(funcao))
    newtonRaphson(erro, a)
    
