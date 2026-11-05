import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

# ==========================================
# 1. Parâmetros Físicos (Corda Genérica)
# ==========================================
L = 1.0       # Comprimento da corda
c = 1.0       # Velocidade de propagação da onda
N_termos = 150 # Quantidade de termos da série de Fourier

# ==========================================
# 2. Condição Inicial f(x)
# ==========================================
def f(x):
    # O professor pediu para testar f(x) = x ou f(x) = x**2
    return x**2
    
    # DICA: Para testar a segunda função do exercício, 
    # comente a linha 'return x' acima e descomente a linha abaixo:
    # return x**2

# ==========================================
# 3. Pré-cálculo dos Coeficientes
# ==========================================
# Com velocidade inicial nula, a fórmula dos coeficientes da 
# série de senos é idêntica à do calor.
def calcula_cn(n, L):
    integrando = lambda x: f(x) * np.sin((n * np.pi * x) / L)
    integral, _ = quad(integrando, 0, L)
    return (2.0 / L) * integral

cn_values = [calcula_cn(n, L) for n in range(1, N_termos + 1)]

# ==========================================
# 4. Solução Matemática u(x,t) (Equação da Onda)
# ==========================================
def u(x, t, L, c, N, coeficientes):
    soma = np.zeros_like(x)
    for n in range(1, N + 1):
        cn = coeficientes[n-1]
        
        # A MUDANÇA PRINCIPAL: sai a exponencial (calor) e entra o cosseno (onda)
        # Formula: sin(n * pi * x / L) * cos(n * pi * c * t / L)
        termo = cn * np.sin((n * np.pi * x) / L) * np.cos((n * np.pi * c * t) / L)
        soma += termo
        
    return soma

# ==========================================
# 5. Simulação e Gráficos (Separados)
# ==========================================
x = np.linspace(0, L, 200)

# Tempos para observar a corda vibrando
tempos = [0.0, 0.25, 0.5, 0.75, 1.0] 

# O laço 'for' agora cria, desenha e mostra um gráfico completo por vez
for t in tempos:
    # 1. Cria uma nova "tela" em branco para este tempo específico
    plt.figure(figsize=(8, 5))
    
    # 2. Calcula a matemática
    deslocamento = u(x, t, L, c, N_termos, cn_values)
    
    # 3. Plota a linha
    plt.plot(x, deslocamento, label=f't = {t} s', linewidth=2, color='#1f77b4')
    
    # 4. Configurações visuais do gráfico atual
    plt.title(f'Equação da Corda: Retrato no instante t = {t} s')
    plt.xlabel('Posição na corda (x)')
    plt.ylabel('Deslocamento u(x,t)')
    
    # TRUQUE IMPORTANTE: Fixar o eixo Y para a "câmera" não tremer
    # Como a função inicial f(x)=x vai até 1.0, fixar entre -1.5 e 1.5 é ideal
    plt.ylim(-1.5, 1.5) 
    
    plt.grid(True, linestyle='--', alpha=0.7)
    plt.legend()
    
    # 5. Mostra o gráfico na tela. 
    # O código só vai calcular o próximo tempo quando você fechar a janela deste gráfico!
    plt.show()