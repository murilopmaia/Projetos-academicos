import random

def imprimir_sudoku(sudoku):
    horizontal_border = "+-------+-------+-------+"

    for i in range(9):
        if i % 3 == 0:
            print(horizontal_border)
        for j in range(9):
            if j % 3 == 0:
                print("| ", end="")
            if j == 8:
                print(" " if sudoku[i][j] == 0 else sudoku[i][j], "|")
            else:
                print(f"{' ' if sudoku[i][j] == 0 else sudoku[i][j]} ", end="")
    print(horizontal_border)



def vlist(lista):
        if isinstance(lista, list):
            return lista
        else:
            return [lista]

def vizinhacaComun(sudoku, xi, xj):
    ai, aj = xi
    bi, bj = xj
    vizinhos = set()
    if ai == bi:
        for i in range(0, 9):
            vizinhos.add((ai, i))
    if aj == bj:
        for i in range(0, 9):
            vizinhos.add((i, aj))

    if (ai - ai%3) == (bi - bi%3) and (aj - aj%3) == (bj - bj%3):
        for a in range(0, 3):
            for b in range(0, 3):
                vizinhos.add((a + ai - ai%3, b + aj - aj%3))

    if xi in vizinhos:
        vizinhos.remove(xi)
    if xj in vizinhos:
        vizinhos.remove(xj)

    return vizinhos
def vizinhaca(sudoku, xi, xj):
    ai, aj = xi
    vizinhos = set()
    for i in range(0, 9):
        vizinhos.add((i, aj))
        vizinhos.add((ai, i))
    
    for a in range(0, 3):
            for b in range(0, 3):
                
                vizinhos.add((a + ai - ai%3, b + aj - aj%3))

    if xi in vizinhos:
        vizinhos.remove(xi)
    if xj in vizinhos:
        vizinhos.remove(xj)
    
    return vizinhos

def setdominio(sudoku, x):
    i, j = x
    d = list(range(1, 10))
    if sudoku[i][j] not in d:
        #verificar linha e coluna
        for a in range(0, 9):
            if sudoku[a][j] in d:
                d.remove(sudoku[a][j])
            if sudoku[i][a] in d:
                d.remove(sudoku[i][a])
        #verificar bloco
        for a in range(0, 3):
            for b in range(0, 3):
                if sudoku[a + i - i%3][b + j - j%3] in d:
                    d.remove(sudoku[a + i - i%3][b + j - j%3])
        #verifica se o dominio possui apenas um elemento, caso possua deixará de ser uma lista
        if len(d) == 1:
            sudoku[i][j] = d.pop()
        elif len(vlist(sudoku[i][j])) > 1:
            sudoku[i][j] = [ele for ele in sudoku[i][j] if ele in d]
        else:
            sudoku[i][j] = d.copy()
    
    
def revisar(sudoku, xi, xj, xm):
    
    revisado = True
    #para determinar os dominios do sudoku
    setdominio(sudoku, xi)
    setdominio(sudoku, xj)
    setdominio(sudoku, xm)
    ai, aj = xi
    bi, bj = xj
    ci, cj = xm

    pos = vlist(sudoku[ci][cj]).copy()
    for x in vlist(sudoku[ai][aj]):
        for y in vlist(sudoku[bi][bj]):
            if x != y:
                for z in vlist(sudoku[ci][cj]):
                    if x != z and y != z and z in pos:
                        pos.remove(z)
                      
    new = [elem for elem in vlist(sudoku[ci][cj]) if elem not in pos] 
    if vlist(sudoku[ci][cj]) == new:
        revisado = False
    else:
        
        sudoku[ci][cj] = new.copy()
        sudoku[ci][cj] = sudoku[ci][cj] if len(sudoku[ci][cj]) > 1 else sudoku[ci][cj][0] if len(sudoku[ci][cj]) == 1 else []

    
    return revisado

def PC_2(sudoku):
    # inicializando a fila com todos os arcos do sudoku
   
    fila = [] 
    for i in range(9):
        for j in range(9): 
            for vizinho in vizinhaca(sudoku, (i, j), (i, j)):
                for vizinho2 in vizinhacaComun(sudoku, vizinho, (i, j)):
                    fila.append(((i, j), vizinho, vizinho2)) 
    while len(fila) != 0:
        xi, xj, xm = fila.pop(0)
        if revisar(sudoku, xi, xj, xm):
                
            ai, aj = xm
            if len(vlist(sudoku[ai][aj])) == 0:
            
                return False
            for xk in vizinhaca(sudoku, xm, xi):
                if xk != xj:
                    for xl in vizinhacaComun(sudoku, xk, xm):
                        fila.append((xk, xm, xl))
        
            
    return True


def main():
    sudoku = [
[0, 0, 0, 5, 0, 9, 8, 0, 0],
[0, 0, 0, 3, 1, 8, 4, 7, 0],
[0, 7, 1, 0, 0, 0, 5, 0, 0],
[0, 0, 0, 6, 8, 5, 0, 0, 7],
[2, 0, 9, 7, 4, 0, 0, 0, 0],
[0, 0, 0, 0, 0, 3, 0, 4, 6],
[3, 0, 2, 0, 9, 0, 0, 0, 4],
[7, 0, 0, 0, 3, 4, 9, 5, 0],
[9, 0, 0, 1, 5, 6, 7, 2, 0]
    ]
    print('new')
    if PC_2(sudoku):
        imprimir_sudoku(sudoku)
    else:
        print("Não foi possível resolver o Sudoku.")
if __name__ == '__main__':
    main()