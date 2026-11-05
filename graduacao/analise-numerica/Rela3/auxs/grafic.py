import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math

def plot_and_compare(y, yi, x, func):
    # Verifica se o comprimento de y e x são iguais
    if len(y) != len(x):
        raise ValueError("Os vetores y e x devem ter o mesmo comprimento")
    
    # Calcula os valores da função aplicada a x
    func_values = func(x)
    
    # Plota y e func_values
    plt.figure(figsize=(10, 5))
    plt.plot(x, y, 'bo-', label='Diferenças finitas')
    plt.plot(x, yi, 'g^-', label='"Shooting"')
    plt.plot(x, func_values, 'r*-', label='Solução Verdadeira')
    plt.xlabel('x')
    plt.ylabel('Valores')
    plt.title('Comparação')
    plt.legend()
    plt.grid(True)
    plt.show()
    
    # Calcula a diferença absoluta em porcentagem
    diff_percentage = np.abs((y - func_values) / func_values) * 100
    diff_percentages = np.abs((yi - func_values) / func_values) * 100
    # Cria um DataFrame para comparar os valores
    comparison_table = pd.DataFrame({
        'x': x,
        'yDifFint': y,
        'yShooting': yi,
        'yVerdadeiro': func_values,
        'Erro(%) Dif Finitas': diff_percentage,
        'Erro(%) Shooting': diff_percentages
    })
    
    # Print a tabela de comparação
    print(comparison_table.to_string(index=False))

# Exemplo de uso da função
yi = np.array([40.0,52.8117043975707,65.9517989918621,79.5517940514426,93.7478026774707,108.681903067154,124.503560477812,141.371123123019,159.453406972230,178.931385315071,200.000000000000])
x = np.array([0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0])
y = np.array([40.0,52.8140890527647,65.9563189960570,79.5581121293096,93.7554863838548,108.690415502239,124.512248775645,141.379204536808,159.459952343339,178.935299673303,200.0])
def exemplo_func(x):
    return 73.4523*math.e**(0.1*x) - 53.4523*math.e**(-0.1*x) + 20


plot_and_compare(y, yi, x, exemplo_func)