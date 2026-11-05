import pandas as pd

def process_csv(file_path, columns_to_remove=None, max_rows=100):
    # Lê o arquivo CSV
    df = pd.read_csv(file_path)
    
    # Exclui as colunas especificadas, se houver
    if columns_to_remove:
        df = df.drop(columns=columns_to_remove, errors='ignore')
    
    # Limita o número de linhas a max_rows
    #df = df.head(max_rows)
    
    # Mostra o DataFrame resultante
    print("DataFrame resultante:")
    print(df)

  
    
    # Opcional: Salva o DataFrame resultante em um novo arquivo CSV
    output_file_path = 'processed_' + file_path
    df.to_csv(output_file_path, index=False)
    print(f"Arquivo processado salvo em: {output_file_path}")

# Exemplo de uso
file_path = 'Train.csv'  # Substitua pelo caminho do seu arquivo CSV
columns_to_remove = [ 'Vision Sharpness', 'Blood Pressure (s/d)',
                      'Physical Activity Level', 'Smoking Status', 'Alcohol Consumption',
                      'Chronic Diseases', 'Medication Use', 'Family History',
                      'Sleep Patterns', 'Income Level', 'Pollution Exposure', 'Sun Exposure']  # Substitua pelos nomes das colunas que deseja remover
process_csv(file_path, columns_to_remove=columns_to_remove, max_rows=1000)

# "Education Level"