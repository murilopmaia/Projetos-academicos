import sympy as sy
import sys

def sistema(ini: dict, funs: dict, a: float, b: float, h: float):
   
    xi = a
    soluc = [(xi, ini.copy())]
   
    n = int((b-a)/h)
    for i in range(0, n):
        k1 = {}
        for key in ini.keys():
            expr = sy.sympify(funs[key+"'"]).subs('x', xi)
            for key2, val2 in ini.items():
                expr = expr.subs(key2, val2)
            k1[key] = sy.N(expr)
        
        k2 = {}
        for key in ini.keys():
            expr = sy.sympify(funs[key+"'"]).subs('x', xi + (1/2)*h)
            for key2, val2 in ini.items():
                expr = expr.subs(key2, val2 + (1/2)*h*k1[key2])
            k2[key] = sy.N(expr)

        k3 = {}
        for key in ini.keys():
            expr = sy.sympify(funs[key+"'"]).subs('x', xi + (1/2)*h)
            for key2, val2 in ini.items():
                expr = expr.subs(key2, val2 + (1/2)*h*k2[key2])
            k3[key] = sy.N(expr)
        
        k4 = {}
        for key in ini.keys():
            expr = sy.sympify(funs[key+"'"]).subs('x', xi + h)
            for key2, val2 in ini.items():
                expr = expr.subs(key2, val2 + h*k3[key2])
            k4[key] = sy.N(expr)
        
        for key in ini.keys():
            ini[key] = ini[key] + (1/6)*(k1[key] + 2*k2[key] + 2*k3[key] + k4[key])*h
            
        xi += h
        soluc.append((xi, ini.copy()))
    return soluc
    
def main():
    ini = {}
    funs = {}

    with open(sys.argv[1], 'r') as arq:
        linha = arq.readline().strip().replace(" ", "")
        while linha != '/':
            var, valor = linha.split('=')
            ini[var] = float(valor)
            linha = arq.readline().strip().replace(" ", "")

        a, b = [float(x) for x in arq.readline().strip().replace(' ', '').split(',')]
        h = float(arq.readline().strip().replace(" ", ""))

        linha = arq.readline()
        linha = arq.readline().strip().replace(" ", "")
        while linha != '' and linha != '\n' and linha != ' ':
            var, fun = linha.split('=')
            funs[var] = fun
            linha = arq.readline().strip().replace(" ", "")

    soluc = sistema(ini, funs, a, b, h)

    with open(sys.argv[2], 'w') as arq:
        arq.write('x | ')
        for key in soluc[0][1]:
            arq.write(f'{key} | ')
        for sol in soluc:
            arq.write(f'\n{sol[0]} | ')
            for re in sol[1].values():
                arq.write(f'{re} | ')


if __name__ == '__main__':
    main()