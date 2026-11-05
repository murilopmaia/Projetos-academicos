import numpy as np
import matplotlib.pyplot as plt

# Definindo a função original
def f(x):
    return np.exp(x) * np.sin(x)

# Definindo a expansão de Taylor (Polinômio de grau 5 calculado no LaTeX)
def taylor_p5(x):
    return x + x**2 + (x**3 / 3) - (x**5 / 30)

# Criando o vetor de dados (x variando de -3 a 3 para boa visualização)
x_vals = np.linspace(-1, 10, 400)
y_original = f(x_vals)
y_taylor = taylor_p5(x_vals)

# Configurando o gráfico
plt.figure(figsize=(10, 6))

# Plotando as curvas
plt.plot(x_vals, y_original, label='$f(x) = e^x \sin(x)$', color='blue', linewidth=2)
plt.plot(x_vals, y_taylor, label='Expansão de Taylor (Grau 5)', color='red', linestyle='--', linewidth=2)

# Adicionando o ponto de expansão (x0 = 0)
plt.scatter([0], [0], color='black', zorder=5, label='Ponto de Expansão $x_0 = 0$')

# Limites do eixo y para evitar que o gráfico fique muito esticado nas pontas
plt.ylim(-10, 15)

# Títulos e legendas
plt.title('Aproximação por Série de Taylor ao Redor de $x_0 = 0$', fontsize=14)
plt.xlabel('x', fontsize=12)
plt.ylabel('y', fontsize=12)
plt.axhline(0, color='black',linewidth=0.8, linestyle='-')
plt.axvline(0, color='black',linewidth=0.8, linestyle='-')
plt.grid(True, linestyle=':', alpha=0.7)
plt.legend(fontsize=12)

# Exibindo o gráfico
plt.show()