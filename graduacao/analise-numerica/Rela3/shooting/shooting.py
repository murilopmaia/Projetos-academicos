from Dependencias import sistemas as sis
import sys

def shooting(fun: str, var: str, shoot1: float, shoot2, ini: float, fim: float, a: float, b: float, h: float):
    var = var.replace("'", "")
    fun = fun.replace(var+"'", "z")

    funs = {
        var+"'": 'z',
        "z'": fun
    }

    vars1 = {
        var: ini,
        'z': shoot1
    }

    result1 = sis.sistema(vars1, funs, a, b, h)

    vars2 = {
        var: ini,
        'z': shoot2
    }
    
    result2 = sis.sistema(vars2, funs, a, b, h)

    y1b = result1[-1][1][var]
    y2b = result2[-1][1][var]
    z = shoot1 + ((shoot2 - shoot1)/(y2b - y1b))*(fim - y1b)
    
    vars3 = {
        var: ini,
        'z': z
    }
    result3 = sis.sistema(vars3, funs, a, b, h)
    result3 = [[res[0], res[1][var]] for res in result3]
    return result3

def main():
    with open(sys.argv[1], 'r') as arq:
        var, fun = arq.readline().strip().replace(' ', '').split('=')
        shoot1, shoot2 = [float(x) for x in arq.readline().strip().replace(' ', '').split(',')]
        ini, fim = [float(x) for x in arq.readline().strip().replace(' ', '').split(',')]
        a, b = [float(x) for x in arq.readline().strip().replace(' ', '').split(',')]
        h = float(arq.readline().strip().replace(' ', ''))

    result = shooting(fun, var, shoot1, shoot2, ini, fim, a, b, h)
    
    with open(sys.argv[2], 'w') as arq:
        for res in result:
           
            arq.write(f'{res[0]} | {res[1]}\n')
        
if __name__ == '__main__':
    main()