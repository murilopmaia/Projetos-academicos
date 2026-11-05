import sys
import sympy as sy


def f(x: int|float) -> float|int:

    expr = sy.sympify(funcao).subs('x', x)
    return sy.N(expr)
    
    

def bisse(erro: float, a: float, b: float) -> None:
    steps = -1
    fa = f(a)
    fb = f(b)
    
    with open(sys.argv[2], "w") as arq:
        if fa * fb < 0:
            while True:
                steps += 1
                c: float = (b+a) / 2
                fc = f(c)

                arq.write(f"k = {steps} | a = {a: .6f} | b = {b: .6f} | f(a) = {fa: .6f} | f(b) = {fb: .6f} | b-a = {b-a: .6f} | c = {c} | f(c) = {fc: .6f}\n")

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


if __name__ == "__main__":
    with open(sys.argv[1], "r") as arq:
        erro = float(arq.readline().replace(" ", "").replace("erro=", ""))
        a = float(arq.readline().replace(" ", "").replace("a=", ""))
        b = float(arq.readline().replace(" ", "").replace("b=", ""))
        funcao = arq.readline().replace(" ", "").replace("funcao=", "")
    bisse(erro, a, b)

   