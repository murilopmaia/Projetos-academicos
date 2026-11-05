import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad
from matplotlib import cm 

# ==========================================
# 1. Parâmetros Físicos e de Simulação
# ==========================================
L = 5.0e-6          # Comprimento da haste (5 micrômetros)
alpha_sq = 1.11e-4  # Difusividade térmica do cobre
N_termos = 100      # Termos da série de Fourier
T_max_ns = 100.0    # Tempo máximo em nanossegundos
T_pico = 65.0       # Temperatura máxima no centro (°C)

# ==========================================
# 2. Condição Inicial e Coeficientes
# ==========================================
def f(x):
    return 4 * T_pico * ((x * (L - x)) / L**2)

def calcula_cn(n, L):
    integrando = lambda x: f(x) * np.sin(n * np.pi * x / L)
    integral, _ = quad(integrando, 0, L)
    return (2.0 / L) * integral

cn_values = [calcula_cn(n, L) for n in range(1, N_termos + 1)]

# ==========================================
# 3. Solução em Malha (Grid 2D)
# ==========================================
def u_grid(X, T, L, alpha_sq, N, coeficientes):
    soma = np.zeros_like(X)
    for n in range(1, N + 1):
        cn = coeficientes[n-1]
        termo = cn * np.sin(n * np.pi * X / L) * np.exp(-alpha_sq * (n * np.pi / L)**2 * T)
        soma += termo
    return soma

# ==========================================
# 4. Geração da Malha
# ==========================================
# Eixo espacial (convertido visualmente depois) e temporal (em segundos reais)
x_points = np.linspace(0, L, 100)
t_points = np.linspace(0, T_max_ns * 1e-9, 100)

X_grid, T_grid = np.meshgrid(x_points, t_points)
Z_temperatura = u_grid(X_grid, T_grid, L, alpha_sq, N_termos, cn_values)

# Convertendo as grades para as unidades de visualização (micrômetros e nanossegundos)
X_visual = X_grid * 1e6
T_visual = T_grid * 1e9

# ==========================================
# 5. Visualização 3D
# ==========================================
fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(projection='3d')

superficie = ax.plot_surface(X_visual, T_visual, Z_temperatura, 
                              cmap=cm.inferno, 
                              linewidth=0,     
                              antialiased=True)

fig.colorbar(superficie, ax=ax, shrink=0.5, aspect=10, label='Temperatura Relativa (°C)')

ax.set_title('Evolução Térmica 3D em Trilha de Semicondutor')
ax.set_xlabel(r'Posição ($\mu$m)')
ax.set_ylabel('Tempo (ns)')
ax.set_zlabel('Temperatura (°C)')

ax.view_init(elev=25, azim=40)
plt.show()