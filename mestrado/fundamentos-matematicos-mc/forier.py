import matplotlib.pyplot as plt
import numpy as np


def f_original(x):
 
    x_mod = np.mod(x + 5, 10) - 5
    return np.where((x_mod >= 0) & (x_mod < 5), 3.0, 0.0)


def fourier_series(x, max_n):
    
    result = np.full_like(x, 1.5)

    for n in range(1, max_n + 1):

        coef = (3 / (n * np.pi)) * (1 - (-1) ** n)
        result += coef * np.sin(n * np.pi * x / 5)

    return result


# Vetor de pontos no eixo x de -10 a 10
x = np.linspace(-10, 10, 2000)

# Criação da figura
fig, ax = plt.subplots(figsize=(10, 6))

# Plota a onda quadrada original
ax.plot(
    x,
    f_original(x),
    label="Função Original f(x)",
    color="black",
    linewidth=2.5,
    linestyle="--",
)

# Plota as aproximações variando o limite superior n da somatória
for max_n in [1, 5, 15, 50]:
    y = fourier_series(x, max_n)
    ax.plot(x, y, label=f"Série (até n={max_n})", alpha=0.85)

# Configurações do gráfico
ax.set_title(
    "Aproximação da Série de Fourier para f(x)"
)
ax.set_xlabel("x")
ax.set_ylabel("f(x)")
ax.grid(True, linestyle=":", alpha=0.6)
ax.legend(loc="upper right")

# Ajusta o layout e exibe o gráfico
plt.tight_layout()
plt.show()