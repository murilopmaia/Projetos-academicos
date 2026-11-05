import matplotlib.pyplot as plt
import numpy as np


# Duas listas com tempo em segundos
lista1 = []
with open(".\\Insertion\\src\\ResultadoJava.txt", "r") as arquivo:
    linha = arquivo.readline()
    while linha != None and linha != "":
        lista1.append(float(linha))
        linha = arquivo.readline()

lista2 = []
with open(".\\output\\resultadosC.txt", "r") as arquivo:
    linha = arquivo.readline()
    while linha != None and linha != "":
        lista2.append(float(linha))
        linha = arquivo.readline()

# Verificar se ambas as listas têm o mesmo número de elementos
if len(lista1) != len(lista2):
    print("As listas não têm o mesmo número de elementos.")
    exit()

# Dividir as listas em quatro partes
tamanho = len(lista1)
quarto = tamanho // 4

# Criar quatro subplots
fig, axs = plt.subplots(2, 2, figsize=(12, 8))
fig.suptitle('Comparação do tempo de processamento entre C e Java divididas em quartos para melhor visualização')

# Plotar os gráficos para cada quarto
for i in range(4):
    row = i // 2
    col = i % 2
    inicio = i * quarto
    fim = (i + 1) * quarto
    indices = range(inicio, fim)
    axs[row, col].plot(indices, lista1[inicio:fim], label='Java', color='blue')
    axs[row, col].plot(indices, lista2[inicio:fim], label='C', color='red')
    axs[row, col].set_title(f'Quarto {i+1}')
    axs[row, col].set_xlabel('Elemento')
    axs[row, col].set_ylabel('Tempo (segundos)')
    axs[row, col].legend()
    axs[row, col].grid(True)

#estatisticas

def showEst(est: dict):
    for chave, valor in est.items():
        print(f"{chave.capitalize()}: {valor}")


lista1 = np.array(lista1)
lista2 = np.array(lista2)


estJava = {}
estC = {}

estJava["máximo"] = lista1.max()
estC["máximo"] = lista2.max()

estJava["mínimo"] = lista1.min()
estC["mínimo"] = lista2.min()

estJava["amplitude"] = lista1.ptp()
estC["amplitude"] = lista2.ptp()

estJava["média"] = lista1.mean()
estC["média"] = lista2.mean()

estJava["mediana"] = np.median(lista1)
estC["mediana"] = np.median(lista2)

estJava["variância"] = np.var(lista1)
estC["variância"] = np.var(lista2)

estJava["desvio_padrão"] = np.std(lista1)
estC["desvio_padrão"] = np.std(lista2)

print("Java\n")
showEst(estJava)

print("\nC\n")
showEst(estC)

# Ajustar layout
plt.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.show()