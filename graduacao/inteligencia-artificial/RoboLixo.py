import os
import time
import sys



if os.name == "nt":
    import msvcrt
else:
    import termios

def imprimeCasa(casa: list[list[int|str]]) -> None:
    for x in casa:
        for y in x:
            print(f"{y: ^4}", end="")
        print()


def limpar_buffer():
    if os.name == "nt":
        while msvcrt.kbhit():
            msvcrt.getch()
    else:
        termios.tcflush(sys.stdin, termios.TCIOFLUSH)

def limpar_tela():
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")

if __name__ == "__main__":

    casa: list[list[int|str]] = [
        [0, 0, 1, 0],
        [1, 0, 0, 0],
        [1, 1, 0, 1],
        [0, 0, 1, 0]
    ]
    i: int = 0
    j: int = 0
    change: int = 1
    tamMax: int = len(casa)
    limpeza: int = 0

    while i != tamMax:

        if casa[i][j] == 1:
            limpeza += 1
            casa[i][j] = "_"
            imprimeCasa(casa)
            print("  Limpando...")
            time.sleep(2)
            limpar_tela()
        else:
            casa[i][j] = "_"
            
        imprimeCasa(casa)
        limpar_buffer()
        print("  Press Enter")
        casa[i][j] = 0

        input()
        limpar_tela()
        
        if change == 1:
            j += 1
            if j == tamMax:
                i += 1
                j -= 1
                change = -1
        else:
            j -= 1
            if j == -1:
                i += 1
                j += 1
                change = 1
   
    print("Casa limpa :3")
    print(f"{limpeza} limpezas realizadas!!")
    

