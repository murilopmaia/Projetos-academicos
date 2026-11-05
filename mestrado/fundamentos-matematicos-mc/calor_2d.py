import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

# ==========================================
# 1. Parâmetros Físicos (Trilha de Cobre)
# ==========================================
L = 5.0e-10      # Comprimento da haste (5 micrômetros)
alpha_sq = 1.11e-4  # Difusividade térmica do cobre (m²/s)
N_termos = 100      # Quantidade de termos da série de Fourier
T_pico = 65.0       # Temperatura máxima no centro do fio (°C)

# ==========================================
# 2. Condição Inicial f(x)
# ==========================================
def f(x):
    # Parábola de aquecimento com pico em L/2
    return 4 * T_pico * ((x * (L - x)) / L**2)

# ==========================================
# 3. Pré-cálculo dos Coeficientes
# ==========================================
def calcula_cn(n, L):
    integrando = lambda x: f(x) * np.sin(n * np.pi * x / L)
    integral, _ = quad(integrando, 0, L)
    return (2.0 / L) * integral

# Pré-calculamos a integral apenas uma vez para economizar processamento
cn_values = [calcula_cn(n, L) for n in range(1, N_termos + 1)]

# ==========================================
# 4. Solução Matemática u(x,t)
# ==========================================
def u(x, t, L, alpha_sq, N, coeficientes):
    soma = np.zeros_like(x)
    for n in range(1, N + 1):
        cn = coeficientes[n-1]
        termo = cn * np.sin(n * np.pi * x / L) * np.exp(-alpha_sq * (n * np.pi / L)**2 * t)
        soma += termo
    return soma

# ==========================================
# 5. Simulação e Gráficos
# ==========================================
# 200 pontos espaciais para criar uma curva suave
x = np.linspace(0, L, 200)

# Tempos que queremos observar (em nanossegundos)
tempos_ns = [1, 10, 25, 50, 100] 

plt.figure(figsize=(10, 6))

for t_ns in tempos_ns:
    # A matemática precisa de segundos, então multiplicamos por 10^-9
    t_segundos = t_ns * 1e-9
    temperaturas = u(x, t_segundos, L, alpha_sq, N_termos, cn_values)
    
    # Plota convertendo o eixo x para micrômetros (x * 10^6)
    plt.plot(x * 1e6, temperaturas, label=f't = {t_ns} ns', linewidth=2)

plt.title('Dissipação de Calor em Trilha de Processador (1D)')
plt.xlabel(r'Posição na trilha ($\mu$m)')
plt.ylabel('Temperatura Relativa (°C)')
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()
plt.show()