# Código que transforme um tabuleiro resolvido em um tabuleiro não resolvido
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

def gerarNovoSudoku():
    """
        Gera um sudoku completo

    """

    from random import sample

    # Funções auxiliares
    def numInPos(board, row, col, num):
        # Verifica se o número já está na linha ou coluna
        for x in range(9):
            if board[row][x] == num or board[x][col] == num:
                return False

        # Verifica se o número já está no bloco 3x3
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(3):
            for j in range(3):
                if board[i + start_row][j + start_col] == num:
                    return False
        return True

    def preenchaTabuleiro(board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == 0:
                    for num in sample(range(1, 10), 9):
                        if numInPos(board, i, j, num):
                            board[i][j] = num
                            if preenchaTabuleiro(board):
                                return True
                            board[i][j] = 0
                    return False
        return True

    board = [[0 for _ in range(9)] for _ in range(9)]

    # Preenche as diagonais de blocos 3x3 para iniciar o processo
    for i in range(0, 9, 3):
        nums = sample(range(1, 10), 9)
        for j in range(3):
            for k in range(3):
                board[i + j][i + k] = nums.pop()

    preenchaTabuleiro(board)
    return board

#---------------------------------

def sudokuGerarNivel(sudoku, nivel='facil'):
    """
        Recebe um sudoku completo e retorna um sudoku incompleto, de acordo com o parâmetro nível
        Os níveis possíveis são:
            + facil   (até 4 elementos por linha x coluna x bloco)
            + medio   (até 3 elementos por linha x coluna x bloco)
            + dificil (até 2 elementos por linha x coluna x bloco)

    """

    from random import shuffle
    import copy

    # Funções auxiliares
    def contarNumeros(lista):
        cont = 0
        for item in lista:
            if isinstance(item, int) and item !=0:
                cont += 1

        return cont

    def temMaisItems_Qtd(board, row, col, qtdMax, modo='all'):
        if modo not in ['all', 'any']:
            raise Exception('modo de função tem que ser all ou any')

        # Verifica se a quantidade de números na linha ou coluna é maior que o qtdMax
        tRow = False
        if contarNumeros(board[row]) > qtdMax:
            tRow = True

        auxCol = []
        for x in range(9):
            auxCol.append(board[x][col])

        tCol = False
        if contarNumeros(auxCol) > qtdMax:
            tCol = True

        # Verifica se a quantidade de números no bloco 3x3 é maior que o qtdMax
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        auxBloco = []
        for i in range(3):
            for j in range(3):
                auxBloco.append(board[i + start_row][j + start_col])

        tBloco = False
        if contarNumeros(auxBloco) > qtdMax:
            tBloco = True

        if modo == 'all':
            return tRow and tCol and tBloco
        return tRow or tCol or tBloco

    sudoku = copy.deepcopy(sudoku)

    # verifica parâmetro nivel
    if nivel not in ['facil', 'medio', 'dificil']:
        raise Exception('nível de sudoku inválido')

    # define a quantidade máxima de itens de acordo com o nível escolhido
    qtdObjetivo = 2
    if nivel == 'facil':
        qtdObjetivo = 4
    elif nivel == 'medio':
        qtdObjetivo = 3

    # gera todas as posições possíveis num tabuleiro
    posicoes = []
    for i in range(9):
        for j in range(9):
            posicoes.append((i, j))

    # anda por todo o tabuleiro de maneira aleatória
    shuffle(posicoes)
    for pos in posicoes:
        if temMaisItems_Qtd(sudoku, pos[0], pos[1], qtdObjetivo):
            sudoku[pos[0]][pos[1]] = 0

    # teste final limite
    #   como o tabuleiro é percorrido aleatoriamente, pode ocorrer de ficarem
    #   linhas/colunas/blocos com um número superior ao permitido
    #   por isso é feito uma verificação final
    for i in range(9):
        for j in range(9):
            if temMaisItems_Qtd(sudoku, i, j, qtdObjetivo, 'any'):
                sudoku[i][j] = 0

    return sudoku

# Gera um tabuleiro de Sudoku completo
sudoku_board = gerarNovoSudoku()

# gera o tabuleiro por nível
sudoku_facil   = sudokuGerarNivel(sudoku_board)
sudoku_medio   = sudokuGerarNivel(sudoku_board, 'medio')
sudoku_dificil = sudokuGerarNivel(sudoku_board, 'dificil')

print('Sudoku completo')
imprimir_sudoku(sudoku_board)
print('\nModo fácil')
imprimir_sudoku(sudoku_facil)
print('\nModo médio')
imprimir_sudoku(sudoku_medio)
print('\nModo difícil')
imprimir_sudoku(sudoku_dificil)
for su in sudoku_medio:
    print('[', end='')
    for s in su:
        print(f'{s},', end='')
    print('],',)
    print()