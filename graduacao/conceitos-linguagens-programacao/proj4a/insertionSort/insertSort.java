import java.util.Random;

public class insertSort {
    public static void gerarVetor(int[] array) {
        Random rand = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = rand.nextInt(1024);
        }
    }

    public static void insertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
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
            insertionSort(array);
            endTime = System.nanoTime();

            tempo = (endTime - startTime) / 1e9;
            System.out.printf("%d -> tempo: %f -> tamanho: %d%n", i, tempo, tam);

            if (tam != 100000) {
                tam *= 10;
            }
        }
    }
}
