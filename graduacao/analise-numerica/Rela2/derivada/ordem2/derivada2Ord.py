
import sys

def derivada2Ord(op: str, vetX, vetY):
    if len(vetX) != len(vetY):
        raise Exception('Vetores com tamanhos diferentes')

    
    match op.capitalize():
        case 'Progressiva':
            h = vetX[1] - vetX[0]
            deriPro = (vetY[2] - 2*vetY[1] + vetY[0])/(h**2)
            
            return {'Progressiva' : deriPro}
        case 'Retardada':
            h = vetX[1] - vetX[0]
            deriRet = (vetY[2] - 2*vetY[1] + vetY[0])/(h**2)

            return {'Retardada' : deriRet}
        case 'Centrada':
            h = vetX[1] - vetX[0]
            deriCen = (vetY[2] - 2*vetY[1] + vetY[0])/(h**2)
            
            return {'Centrada' : deriCen}
        case 'Todas':
            h = vetX[1] - vetX[0]
    
            deriPro = (vetY[4] - 2*vetY[3] + vetY[2])/(h**2)
            deriRet = (vetY[2] - 2*vetY[1] + vetY[0])/(h**2)
            deriCen = (vetY[3] - 2*vetY[2] + vetY[1])/(h**2)
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

    result = derivada2Ord(op, vetX, vetY)

    with open(sys.argv[2], 'w') as arq:
        for chave, valor in result.items():
            arq.write(f'Derivada {chave} = {valor}\n')

if __name__ == '__main__':
    main()
