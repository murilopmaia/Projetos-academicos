import java.util.Random;

public class bubleSort {
     public static void gerarVetor(int[] array) {
        Random rand = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = rand.nextInt(1024);
        }
    }

    static void bubbleSort(int array[]) {
        int size = array.length;
        for (int i = 0; i < size - 1; i++)

          for (int j = 0; j < size - i - 1; j++)

            if (array[j] > array[j + 1]) {

              int temp = array[j];
              array[j] = array[j + 1];
              array[j + 1] = temp;
            }
      }

    public static void imprimeVetor(int[] array) {
        System.out.print("\n{" + array[0]);
        for (int i = 1; i < array.length; i++) {
            System.out.print(" ," + array[i]);
        }
        System.out.println("}");
    }

    public static void main(String[] args) {
        long startTime, endTime;
        double tempo;
        long tam = 10;
        int[] array;

        for (int i = 0; i < 10; i++) {
            array = new int[(int) tam];
            gerarVetor(array);

            startTime = System.nanoTime();
            bubbleSort(array);
            endTime = System.nanoTime();

            tempo = (endTime - startTime) / 1e9;
            System.out.printf("%d -> tempo: %f -> tamanho: %d%n", i, tempo, tam);

            if (tempo >= 60) {
                break;
                
            }
            tam *= 10;
        }
    }
}
