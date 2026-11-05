def vizinhaca(sudoku, xi, xj):
    ai, aj = xi
    vizinhos = []
    for i in range(9):  # Devemos iterar até 9, não 8
        if i != ai:
            vizinhos.append([i, aj])
        if i != aj:
            vizinhos.append([ai, i])
    
    for a in range(3):
        for b in range(3):
            if (a + ai - ai % 3) != ai or (b + aj - aj % 3) != aj:
                vizinhos.append([a + ai - ai % 3, b + aj - aj % 3])
    
    if xi in vizinhos:
        vizinhos.remove(xi)
    if xj in vizinhos:
        vizinhos.remove(xj)
    
    return vizinhos

def setdominio(sudoku, x):
    i, j = x
    d = list(range(1, 10))
    if isinstance(sudoku[i][j], int) and sudoku[i][j] != 0:
        return  # Se a célula já tem um valor, não há nada a fazer
    
    for a in range(9):  # Devemos iterar até 9, não 8
        if sudoku[a][j] in d:
            d.remove(sudoku[a][j])
        if sudoku[i][a] in d:
            d.remove(sudoku[i][a])
    
    for a in range(3):
        for b in range(3):
            if sudoku[a + i - i % 3][b + j - j % 3] in d:
                d.remove(sudoku[a + i - i % 3][b + j - j % 3])
    
    sudoku[i][j] = d if len(d) > 1 else d[0]  # Atualiza o domínio ou define o valor único

def revisar(sudoku, xi, xj):
    def vlist(lista):
        if isinstance(lista, list):
            return lista
        else:
            return [lista]
    
    revisado = False
    setdominio(sudoku, xi)
    setdominio(sudoku, xj)
    
    ai, aj = xi
    bi, bj = xj
    
    if isinstance(sudoku[ai][aj], list):
        for x in vlist(sudoku[bi][bj]):
            if x in sudoku[ai][aj]:
                sudoku[ai][aj].remove(x)
                revisado = True
    
    return revisado

def AC_3(sudoku):
    fila = []
    for i in range(9):
        for j in range(9): 
            for vizinho in vizinhaca(sudoku, [i, j], [i, j]):
                fila.append(([i, j], vizinho))
    
    while len(fila) != 0:
        xi, xj = fila.pop(0)
        if revisar(sudoku, xi, xj):
            ai, aj = xi
            if len(sudoku[ai][aj]) == 0:
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
    
    AC_3(sudoku)
    
    for su in sudoku:
        for s in su:
            print(s, end = ' ')
        print()
    
if __name__ == '__main__':
    main()
