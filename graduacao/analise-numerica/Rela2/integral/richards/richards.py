import sys
from Dependencia.trapezio import trapezio

def richards(fun, a, b):
    h1 = trapezio(fun, a, b, 1)
    h2 = trapezio(fun, a, b, 2)
    h3 = trapezio(fun, a, b, 4)
    
    I1 = (4/3)*h2 - (1/3)*h1
    I2 = (4/3)*h3 - (1/3)*h2
    I = (16/15)*I2 - (1/15)*I1
    
    return I

def main():
    with open(sys.argv[1], 'r') as arq:
        fun = arq.readline().strip().replace(" ", "").replace("fun=", "")
        a = float(arq.readline().strip().replace(" ", "").replace("a=", ""))
        b = float(arq.readline().strip().replace(" ", "").replace("b=", ""))
        

    result = richards(fun, a, b)

    with open(sys.argv[2], 'w') as arq:
        arq.write(f'Integral = {result}')

if __name__ == '__main__':
    main()