def vlist(lista):
    return lista if isinstance(lista, list) else [lista]

def vizinhaca(sudoku, xi):
    ai, aj = xi
    vizinhos = set()
    for i in range(9):
        if i != ai:
            vizinhos.add((i, aj))
        if i != aj:
            vizinhos.add((ai, i))
    
    box_row, box_col = ai // 3 * 3, aj // 3 * 3
    for i in range(3):
        for j in range(3):
            if (box_row + i, box_col + j) != (ai, aj):
                vizinhos.add((box_row + i, box_col + j))
    return vizinhos

def setdominio(sudoku, x):
    i, j = x
    if sudoku[i][j] == 0 or isinstance(sudoku[i][j], list):
        d = set(range(1, 10))
        # Verificar linha e coluna
        for a in range(9):
            if isinstance(sudoku[a][j], int) and sudoku[a][j] in d:
                d.remove(sudoku[a][j])
            if isinstance(sudoku[i][a], int) and sudoku[i][a] in d:
                d.remove(sudoku[i][a])
        # Verificar bloco
        for a in range(3):
            for b in range(3):
                valor = sudoku[i//3*3 + a][j//3*3 + b]
                if isinstance(valor, int) and valor in d:
                    d.remove(valor)
        # Atualizar domínio
        sudoku[i][j] = list(d) if len(d) > 1 else d.pop() if len(d) == 1 else []

def revisar(sudoku, xi, xj, xm):
    revisado = False
    ai, aj = xi
    bi, bj = xj
    mi, mj = xm

    if isinstance(sudoku[ai][aj], list):
        for x in vlist(sudoku[ai][aj]):
            if all(x not in vlist(sudoku[bi][bj]) for z in vlist(sudoku[mi][mj])):
                sudoku[ai][aj].remove(x)
                revisado = True
                if len(sudoku[ai][aj]) == 1:
                    sudoku[ai][aj] = sudoku[ai][aj][0]
    return revisado

def PC_2(sudoku):
    # Inicializando a fila com todas as combinações de três variáveis
    fila = []
    for i in range(9):
        for j in range(9):
            a = vizinhaca(sudoku, (i, j))
            a.add((i, j))
            for xi in a:
                for xj in vizinhaca(sudoku, xi):
                    if xi != xj:
                        for xm in vizinhaca(sudoku, xj):
                            if xm != xi and xm != xj:
                                fila.append((xi, xj, xm))

    while fila:
        xi, xj, xm = fila.pop(0)
        if revisar(sudoku, xi, xj, xm):
            ai, aj = xi
            if len(vlist(sudoku[ai][aj])) == 0:
                return False
            for xk in vizinhaca(sudoku, xi):
                for xl in vizinhaca(sudoku, xk):
                    if xk != xl:
                        fila.append((xi, xk, xl))
                        fila.append((xk, xi, xl))
                        fila.append((xk, xl, xi))
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

    # Inicializa os domínios
    for i in range(9):
        for j in range(9):
            setdominio(sudoku, (i, j))
    for su in sudoku:
            for s in su:
                print(f' {s} ', end='')
            print()
    if PC_2(sudoku):
        for su in sudoku:
            for s in su:
                print(f' {s} ', end='')
            print()
    else:
        print("No solution found")

if __name__ == '__main__':
    main()
