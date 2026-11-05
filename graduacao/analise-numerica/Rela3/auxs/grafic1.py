import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math

def plot_and_compare(euler, eulermod, heun, ord2, ord3, ord4, x, func):
    # Verifica se o comprimento de y e x são iguais
    if len(euler) != len(x):
        raise ValueError("Os vetores y e x devem ter o mesmo comprimento")
    
    # Calcula os valores da função aplicada a x
    func_values = func(x)
    
    # Plota y e func_values
    plt.figure(figsize=(10, 5))
    plt.plot(x, heun, 'bo-', label='Heun')
    plt.plot(x, euler, 'g^-', label='Euler')
    plt.plot(x, eulermod, 'ys-', label='Euler Modificado')
    plt.plot(x, ord2, 'c*-', label='Ralston')
    plt.plot(x, ord3, 'md-', label='RK Ord 3')
    plt.plot(x, ord4, 'kp-', label='RK Ord 4')
    plt.plot(x, func_values, 'r*-', label='Solução Verdadeira')
    plt.xlabel('x')
    plt.ylabel('Valores')
    plt.title('Comparação')
    plt.legend()
    plt.grid(True)
    plt.show()
    
    # Calcula a diferença absoluta em porcentagem
    diff_percentageHeun = np.abs((heun - func_values) / func_values) * 100
    diff_percentageEuler = np.abs((euler - func_values) / func_values) * 100
    diff_percentageEulermod = np.abs((eulermod - func_values) / func_values) * 100
    diff_percentageord2 = np.abs((ord2 - func_values) / func_values) * 100
    diff_percentageord3 = np.abs((ord3 - func_values) / func_values) * 100
    diff_percentageord4 = np.abs((ord4 - func_values) / func_values) * 100

    # Cria um DataFrame para comparar os valores
    comparison_table = pd.DataFrame({
        'x': x,
        'Erro(%) Euler' : diff_percentageEuler,
        'Erro(%) Heun' : diff_percentageHeun,
        'Erro(%) Euler Mod.' : diff_percentageEulermod,
        'Erro(%) Ralston': diff_percentageord2,
        'Erro(%) RK Ordem 3': diff_percentageord3,
        'Erro(%) RK Ordem 4': diff_percentageord4
    })
    
    # Print a tabela de comparação
    print(comparison_table.to_string(index=False))

# Exemplo de uso da função
euler = np.array([1.0, 5.25000000000000, 5.87500000000000, 5.12500000000000, 4.50000000000000, 4.75000000000000, 5.87500000000000, 7.12500000000000, 7.00000000000000])
eulermod = np.array([1.0, 3.10937500000000, 2.81250000000000, 1.98437500000000, 1.75000000000000, 2.48437500000000, 3.81250000000000, 4.60937500000000, 3.00000000000000])
heun = np.array([1.0, 3.43750000000000, 3.37500000000000, 2.68750000000000, 2.50000000000000, 3.18750000000000, 4.37500000000000, 4.93750000000000, 3.00000000000000])
ord2 = np.array([1.0, 3.27734375000000, 3.10156250000000, 2.34765625000000, 2.14062500000000, 2.85546875000000, 4.11718750000000, 4.80078125000000, 3.03125000000000])
ord3 = np.array([1.0, 3.21875000000000, 3.00000000000000, 2.21875000000000, 2.00000000000000, 2.71875000000000, 4.00000000000000, 4.71875000000000, 3.00000000000000])
ord4 = np.array([1.0, 3.21875000000000, 3.00000000000000, 2.21875000000000, 2.00000000000000, 2.71875000000000, 4.00000000000000, 4.71875000000000, 3.00000000000000])
x = np.array([0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0])

def exemplo_func(x):
    return -0.5*x**4 + 4*x**3 - 10*x**2 + 8.5*x + 1

plot_and_compare(euler, eulermod, heun, ord2, ord3, ord4, x, exemplo_func)