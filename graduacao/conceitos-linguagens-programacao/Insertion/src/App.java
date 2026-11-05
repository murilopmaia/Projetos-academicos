import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class App {
    public static final int TAMANHO_VETOR = 10000;
    public static final int NUM_VETORES = 1024;
    public static void main(String[] args) throws Exception {
        Random random = new Random(5);
        long ini, fim;
        double tempo;
        double vetorTempo[] = new  double[NUM_VETORES];
        int vetor[] = new int[TAMANHO_VETOR];

        
        for (int i = 0; i < NUM_VETORES; i++){
             gerarVetor(vetor, random);
             ini = System.nanoTime();
             insertionSort(vetor);
             fim = System.nanoTime();
             tempo = (fim - ini)/1_000_000_000.0;
             vetorTempo[i] = tempo;
        }

        imprimirVetorTempo(vetorTempo);
        escreverVetorTempo(vetorTempo);
    }

    public static void insertionSort(int vetor[]){
        int chave;
        int j, i;
        for (i = 1; i < TAMANHO_VETOR; i++)
        {
            chave = vetor[i];
            j = i - 1;

            while (j >= 0 && vetor[j] > chave)
            {
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = chave;
        }
    }

    public static void imprimirVetorTempo(double vetor[]){
        System.out.printf("\n[%f", vetor[0]);
        for (int i = 1; i < NUM_VETORES; i++)
        {
            System.out.printf(", %f", vetor[i]);
        }
        System.out.printf("]\n");
    }

    public static void escreverVetorTempo(double vetor[]){
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(".\\ResultadoJava.txt"));
            for (double numero : vetor) {
                writer.write(Double.toString(numero));
                writer.newLine(); // Pula para a próxima linha
            }
            writer.close();
        } catch (IOException e) {
            System.err.println("Erro ao escrever no arquivo: " + e.getMessage());
        }
    }

    public static void gerarVetor(int vetor[], Random random){
        for (int i = 0; i < TAMANHO_VETOR; i++){
            vetor[i] = random.nextInt(1025);
        }
    }
}


