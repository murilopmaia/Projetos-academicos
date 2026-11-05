import matplotlib.pyplot as plt
import numpy as np

def plot_four_functions():
    # Dados para os gráficos
    x1 = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
    y1 = [0.000000, 0.000000,  0.000000, 0.001000, 0.027000, 2.030000, 195.034000]
    x2 = [10, 100, 1000, 10000, 100000, 1000000, 10000000]
    y2 = [0.000004, 0.000025, 0.000305, 0.000735, 0.008043, 0.496017, 44.085881]
    x3 = [10, 100, 1000, 10000]
    y3 = [0.00, 0.00, 0.01, 0.17]
    x4 = [10, 100, 1000, 10000]
    y4 = [0.0, 0.0,  0.0, 0.006]

    # Criar o gráfico
    plt.figure(figsize=(10, 6))

    # Plotar cada função
    plt.plot(x1, y1, label='C')
    plt.plot(x2, y2, label='Java')
    plt.plot(x3, y3, label='prolog')
    plt.plot(x4, y4, label='lisp')

    # Ajustar limites do eixo y para evitar valores extremos da tangente
    plt.xlim(0, 10000)
    plt.ylim(0, 0.006)

    # Adicionar título e legendas
    plt.title('Gráfico QuickSort - zoom 2')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()

    # Adicionar grade
    plt.grid(True)

    # Exibir o gráfico
    plt.show()

# Chamar a função para plotar os gráficos
plot_four_functions()
