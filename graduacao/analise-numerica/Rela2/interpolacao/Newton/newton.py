import sys
import sympy as sy

def newtonRec(f: dict, vetX: list, handle: str):
    
    if f.get(handle) != None:
        return f[handle]
        
    else:
        handle1 = handle.replace(" ", "").split(",")
        xf = int(handle1.pop())
        handle2 = handle.replace(" ", "").split(",")
        xi = int(handle2.pop(0))
        
        re = (newtonRec(f, vetX, ','.join(handle1)) - newtonRec(f, vetX, ','.join(handle2)))/(vetX[xi] - vetX[xf])
        f[handle] = re
        return f[handle]

def newton(vetX, vetY):
    nX = len(vetX)
    nY = len(vetY)
    if nX != nY:
        raise Exception("Vetores com tamanhos diferentes")
    n = nX

    f = {}
    handle = []
    
    for i in range(n):
        f[f'{i}'] = vetY[i]
        handle.append(str(i))
    
    
    handle = ','.join(handle[::-1])
    newtonRec(f, vetX, handle)

    expr = f"{f['0']}"
    for i in range(1, n):
        han = handle[-(2*i+1):]
        expr += f'+ {f[han]}'
        for j in range(i):
            expr += f'*(x - {vetX[j]})'

    
    expr = sy.sympify(expr)
    expressao_simplificada = sy.expand(expr)
    return str(expressao_simplificada)
    

def main() -> None:
    vetX: list
    vetY: list

    with open(sys.argv[1], 'r') as arq:
        vetX = arq.readline().strip().replace(" ", "").split(",")
        vetX = [float(x) for x in vetX]
        vetY = arq.readline().strip().replace(" ", "").split(",")
        vetY = [float(y) for y in vetY]

    result = newton(vetX, vetY)

    with open(sys.argv[2], 'w') as arq:
        arq.write('f(x) = ' + result)

if __name__ == '__main__':
    main()