import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad
from matplotlib import cm 

# ==========================================
# 1. Parâmetros Físicos (Corda Genérica)
# ==========================================
L = 1.0       # Comprimento da corda
c = 1.0       # Velocidade de propagação da onda
N_termos = 100 # Termos da série de Fourier
T_max = 2.0   # Tempo para a onda ir e voltar (um ciclo completo)

# ==========================================
# 2. Condição Inicial f(x) e Coeficientes
# ==========================================
def f(x):
    # Condição inicial do exercício do professor
    return x 

def calcula_cn(n, L):
    integrando = lambda x: f(x) * np.sin(n * np.pi * x / L)
    integral, _ = quad(integrando, 0, L)
    return (2.0 / L) * integral

# Pré-calculamos todos os c_n necessários
cn_values = [calcula_cn(n, L) for n in range(1, N_termos + 1)]

# ==========================================
# 3. Solução Matemática 3D u(X,T)
# ==========================================
def u_grid(X, T, L, c, N, coeficientes):
    """
    Calcula a solução u em uma malha 2D de pontos (X, T).
    """
    soma = np.zeros_like(X)
    for n in range(1, N + 1):
        cn = coeficientes[n-1]
        
        # O termo temporal agora usa COSSENO, caracterizando a vibração
        termo = cn * np.sin(n * np.pi * X / L) * np.cos(n * np.pi * c * T / L)
        soma += termo
        
    return soma

# ==========================================
# 4. Geração da Malha (Grid)
# ==========================================
x_points = np.linspace(0, L, 100)
t_points = np.linspace(0, T_max, 100)

X_grid, T_grid = np.meshgrid(x_points, t_points)
Z_deslocamento = u_grid(X_grid, T_grid, L, c, N_termos, cn_values)

# ==========================================
# 5. Visualização 3D (Diagrama Espaço-Tempo)
# ==========================================
fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(projection='3d')

superficie = ax.plot_surface(X_grid, T_grid, Z_deslocamento, 
                              cmap=cm.coolwarm, # Mapa de cores azul-branco-vermelho
                              linewidth=0,     
                              antialiased=True)

fig.colorbar(superficie, ax=ax, shrink=0.5, aspect=10, label='Deslocamento u(x,t)')

ax.set_title('Diagrama de Espaço-Tempo 3D (Equação da Corda)')
ax.set_xlabel('Posição na corda (x)')
ax.set_ylabel('Tempo (t)')
ax.set_zlabel('Deslocamento u(x,t)')

# Ângulo ajustado para ver bem o ziguezague da onda viajando
ax.view_init(elev=35, azim=-45)

plt.show()