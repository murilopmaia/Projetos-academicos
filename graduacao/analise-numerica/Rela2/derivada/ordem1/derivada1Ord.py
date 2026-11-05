import sys

def derivada1Ord(op: str, vetX, vetY) -> dict:
    if len(vetX) != len(vetY):
        raise Exception('Vetores com tamanhos diferentes')

    match op.capitalize():
        case 'Progressiva':
            h = vetX[1] - vetX[0]
            deriPro = (vetY[1] - vetY[0])/h
            return {'Progressiva' : deriPro}
        case 'Retardada':
            h = vetX[1] - vetX[0]
            deriRet = (vetY[1] - vetY[0])/h
            return {'Retardada' : deriRet}
        case 'Centrada':
            h = vetX[1] - vetX[0]
            deriCen = (vetY[1]  - vetY[0])/(2*h)
            return {'Centrada' : deriCen}
        case 'Todas':
            h = vetX[1] - vetX[0]
    
            deriPro = (vetY[2] - vetY[1])/h
            deriRet = (vetY[1] - vetY[0])/h
            deriCen = (vetY[2]  - vetY[0])/(2*h)
            return {'Progressiva': deriPro,
                    'Retardada': deriRet,
                    'Centrada': deriCen}
        case _:
            raise Exception('Erro na op')
        

def main() -> None:
    with open(sys.argv[1], 'r') as arq:
        op = arq.readline().strip().replace(" ", "").replace("op=", "")
        vetX = arq.readline().strip().replace(" ", "").replace("x=", "").split(',')
        vetY = arq.readline().strip().replace(" ", "").replace("y=", "").split(',')
        vetX = [float(x) for x in vetX]
        vetY = [float(y) for y in vetY]

    result = derivada1Ord(op, vetX, vetY)

    with open(sys.argv[2], 'w') as arq:
        for chave, valor in result.items():
            arq.write(f'Derivada {chave} = {valor}\n')
            
if __name__ == '__main__':
    main()