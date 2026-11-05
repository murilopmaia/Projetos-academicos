

import java.util.Random;

public class quickSort {
    public static void gerarVetor(int[] array) {
        Random rand = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = rand.nextInt(1024);
        }
    }
   // method to find the partition position
  public static int partition(int array[], int low, int high) {
    
    // choose the rightmost element as pivot
    int pivot = array[high];
    
    // pointer for greater element
    int i = (low - 1);

    // traverse through all elements
    // compare each element with pivot
    for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {

        // if element smaller than pivot is found
        // swap it with the greatr element pointed by i
        i++;

        // swapping element at i with element at j
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }

    }

    // swapt the pivot element with the greater element specified by i
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    // return the position from where partition is done
    return (i + 1);
  }

  public static void quickSort(int array[], int low, int high) {
    if (low < high) {

      // find pivot element such that
      // elements smaller than pivot are on the left
      // elements greater than pivot are on the right
      int pi = partition(array, low, high);
      
      // recursive call on the left of pivot
      quickSort(array, low, pi - 1);

      // recursive call on the right of pivot
      quickSort(array, pi + 1, high);
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
            quickSort(array, 0, array.length-1);
            endTime = System.nanoTime();

            tempo = (endTime - startTime) / 1e9;
            System.out.printf("%d -> tempo: %f -> tamanho: %d%n", i, tempo, tam);

            if (tempo < 60) {
                tam *= 10;
            }
        }
    }
}
