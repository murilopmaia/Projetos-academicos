import sys
import sympy as sy

def f(x: int|float) -> float|int:

    fun = funcao.replace("x", str(x))
    return sy.solve(f"{fun}-x")[0]


def secante(erro: float, a: float, b: float) -> None:
    x1 = a
    x2 = b
    steps = -1

    with open(sys.argv[2], "w") as arq:

        while True:
            steps +=1

            fx1 = f(x1)
            fx2 = f(x2)

            x3 = (fx2*x1 - fx1*x2) / (fx2-fx1)
            fx3 = f(x3)

            arq.write(f"k = {steps} | x1 = {x1: .6f} | x2 = {x2: .6f}  ->  x3 = {x3} | f(x3) = {fx3: .6f}\n")

            x1 = x2
            x2 = x3

            if abs(fx3) <= erro:
                break

if __name__ == "__main__":
    with open(sys.argv[1], "r") as arq:
        erro = float(arq.readline().replace(" ", "").replace("erro=", ""))
        a = float(arq.readline().replace(" ", "").replace("x1=", ""))
        b = float(arq.readline().replace(" ", "").replace("x2=", ""))
        funcao = arq.readline().replace(" ", "").replace("funcao=", "")
    
    secante(erro, a, b)