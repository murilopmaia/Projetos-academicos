def vlist(lista):
    if isinstance(lista, list):
        return lista
    else:
        return [lista]

def vizinhaca(sudoku, xi, xj):
    ai, aj = xi
    vizinhos = set()
    for i in range(9):
        vizinhos.add((i, aj))
        vizinhos.add((ai, i))
    
    for a in range(3):
            for b in range(3):
                if (a + ai - ai%3) != ai and (b + aj - aj%3) != aj:
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
        for a in range(9):
            if sudoku[a][j] in d:
                d.remove(sudoku[a][j])
            if sudoku[i][a] in d:
                d.remove(sudoku[i][a])
        #verificar bloco
        for a in range(3):
            for b in range(3):
                if sudoku[a + i - i%3][b + j - j%3] in d:
                    d.remove(sudoku[a + i - i%3][b + j - j%3])
        #verifica se o dominio possui apenas um elemento, caso possua deixará de ser uma lista
       
        if len(d) == 1:
            sudoku[i][j] = d.pop()
        elif len(vlist(sudoku[i][j])) > 1:
            sudoku[i][j] = [ele for ele in sudoku[i][j] if ele in d]
        else:
            sudoku[i][j] = d.copy()
    
    
def revisar(sudoku, xi, xj):
    
    revisado = False
    #para determinar os dominios do sudoku
    setdominio(sudoku, xi)
    setdominio(sudoku, xj)
    ai, aj = xi
    bi, bj = xj
    for x in vlist(sudoku[ai][aj]):
        if (x in vlist(sudoku[bi][bj])) and (len(vlist(sudoku[bi][bj])) == 1):
            sudoku[ai][aj].remove(x)
            revisado = True
    
    return revisado

def AC_3(sudoku):
    # inicializando a fila com todos os arcos do sudoku
    fila = [] 
    for i in range(9):
        for j in range(9): 
            for vizinho in vizinhaca(sudoku, (i, j), (i, j)):
                fila.append(((i, j), vizinho)) 

    while len(fila) != 0:
        xi, xj = fila.pop(0)

        if revisar(sudoku, xi, xj):
            ai, aj = xi
            if len(sudoku[ai][aj]) == 0:
                print(ai, aj)
                return False
            for xk in vizinhaca(sudoku, xi, xj):
                fila.append((xk, xi))
            
    
    return True


def main():
    sudoku = [
        [0, 0, 3, 0, 2, 0, 6, 0, 0],
[9, 0, 0, 3, 0, 5, 0, 0, 1],
[0, 0, 1, 8, 0, 6, 4, 0, 0],
[0, 0, 8, 1, 0, 2, 9, 0, 0],
[7, 0, 0, 0, 0, 0, 0, 0, 8],
[0, 0, 6, 7, 0, 8, 2, 0, 0],
[0, 0, 2, 6, 0, 9, 5, 0, 0],
[8, 0, 0, 2, 0, 3, 0, 0, 9],
[0, 0, 5, 0, 1, 0, 3, 0, 0]
    ]
    
    print(AC_3(sudoku))
    for su in sudoku:
        for s in su:
            
            print(f' {s} ', end='')
        print()
    
if __name__ == '__main__':
    main()