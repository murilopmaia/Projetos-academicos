import numpy as np
import matplotlib.pyplot as plt

# ==========================================
# 1. Definição dos Parâmetros do Sistema
# ==========================================
a = 1.0  # Raio do cilindro interno
b = 5.0  # Raio do cilindro externo
Va = 1.0 # Potencial no cilindro interno (Volts)
Vb = 2.0 # Potencial no cilindro externo (Volts)

# Função do potencial baseada na solução analítica
def calcular_potencial(r):
    return Va + (Vb - Va) * (np.log(r / a) / np.log(b / a))

# ==========================================
# 2. Preparação dos Dados para Visualização
# ==========================================

# Dados para o Gráfico 1D (Apenas a dimensão radial r)
r_1d = np.linspace(a, b, 500)
psi_1d = calcular_potencial(r_1d)

# Dados para o Gráfico 2D (Malha espacial X, Y)
xy_max = b + 1.0
x = np.linspace(-xy_max, xy_max, 600)
y = np.linspace(-xy_max, xy_max, 600)
X, Y = np.meshgrid(x, y)

# Calcula o raio R para cada ponto (x, y) da malha
R = np.sqrt(X**2 + Y**2)

Psi_2d = np.full_like(R, np.nan)

mascara_espacial = (R >= a) & (R <= b)
Psi_2d[mascara_espacial] = calcular_potencial(R[mascara_espacial])

# ==========================================
# 3. Plotagem e Formatação
# ==========================================
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

# --- Plot 1D: Perfil Radial ---
ax1.plot(r_1d, psi_1d, color='#1f77b4', linewidth=2.5)
ax1.set_title('Perfil do Potencial Radial: $\psi(r)$', fontsize=14, pad=15)
ax1.set_xlabel('Distância Radial ($r$)', fontsize=12)
ax1.set_ylabel('Potencial (Volts)', fontsize=12)
ax1.set_xlim(0, b + 1)
ax1.set_ylim(0.8, 2.2)
ax1.axvline(a, color='gray', linestyle='--', label=f'Raio Interno (a={a})')
ax1.axvline(b, color='gray', linestyle=':', label=f'Raio Externo (b={b})')
ax1.grid(True, alpha=0.4)
ax1.legend()

# --- Plot 2D: Corte Transversal (Heatmap) ---
contorno = ax2.contourf(X, Y, Psi_2d, levels=50, cmap='plasma')
ax2.add_patch(plt.Circle((0, 0), a, color='white', fill=True, zorder=2, label='Cilindro Interno'))
ax2.add_patch(plt.Circle((0, 0), b, color='black', fill=False, linewidth=2, zorder=3))
ax2.set_aspect('equal')
ax2.set_title('Corte Transversal 2D', fontsize=14, pad=15)
ax2.set_xlabel('Eixo X', fontsize=12)
ax2.set_ylabel('Eixo Y', fontsize=12)
cbar = fig.colorbar(contorno, ax=ax2, fraction=0.046, pad=0.04)
cbar.set_label('Potencial (Volts)', rotation=270, labelpad=15)
plt.tight_layout()
plt.show()