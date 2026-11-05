import sympy as sy

def localVar(linha: str):
    var = ''
    valor = ''
    for i, el in enumerate(linha):
        if el == '=':
            valor = linha[i+1:]
            break
        var += el
    return [var, float(valor)]

def localFun(linha: str):
    var = ''
    fun = ''
    for i, el in enumerate(linha):
        if el == '=':
            fun = linha[i+1:]
            break
        var += el
    return [var, fun]

def sistema(ini: dict, funs: dict, a: float, b: float, h: float):
   
    xi = a
    soluc = [(xi, ini.copy())]

    n = int((b-a)/h)
    
    for i in range(0, n):
        k1 = {}
        for key, val in ini.items():
            expr = sy.sympify(funs[key+"'"]).subs('x', xi)
            for key2, val2 in ini.items():
                expr = expr.subs(key2, val2)
            k1[key] = sy.N(expr)
        
        k2 = {}
        for key, val in ini.items():
            expr = sy.sympify(funs[key+"'"]).subs('x', xi + (1/2)*h)
            for key2, val2 in ini.items():
                expr = expr.subs(key2, val2 + (1/2)*h*k1[key2])
            k2[key] = sy.N(expr)

        k3 = {}
        for key, val in ini.items():
            expr = sy.sympify(funs[key+"'"]).subs('x', xi + (1/2)*h)
            for key2, val2 in ini.items():
                expr = expr.subs(key2, val2 + (1/2)*h*k2[key2])
            k3[key] = sy.N(expr)
        
        k4 = {}
        for key, val in ini.items():
            expr = sy.sympify(funs[key+"'"]).subs('x', xi + h)
            for key2, val2 in ini.items():
                expr = expr.subs(key2, val2 + h*k3[key2])
            k4[key] = sy.N(expr)
        
        for key, val in ini.items():
            ini[key] = ini[key] + (1/6)*(k1[key] + 2*k2[key] + 2*k3[key] + k4[key])*h
            
        xi += h
        soluc.append((xi, ini.copy()))
    return soluc
    
def main():
    ini = {}
    funs = {}

    with open('.\\input\\input1.txt', 'r') as arq:
        linha = arq.readline().strip().replace(" ", "")
        while linha != '/':
            var, valor = localVar(linha)
            ini[var] = valor
            linha = arq.readline().strip().replace(" ", "")

        a = float(arq.readline().strip().replace(" ", "").replace("a=", ""))
        b = float(arq.readline().strip().replace(" ", "").replace("b=", ""))
        h = float(arq.readline().strip().replace(" ", "").replace("h=", ""))
        linha = arq.readline()

        linha = arq.readline().strip().replace(" ", "")
        while linha != '' and linha != '\n' and linha != ' ':
            var, fun = localFun(linha)
            funs[var] = fun
            linha = arq.readline().strip().replace(" ", "")

    soluc = sistema(ini, funs, a, b, h)
    print(soluc, sep='\n')
if __name__ == '__main__':
    main()