import java.util.Random;

public class mergeSort {
    public static void gerarVetor(int[] array) {
        Random rand = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = rand.nextInt(1024);
        }
    }

    // Merge two subarrays L and M into arr
    public static void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[] = new int[n1];
    int M[] = new int[n2];

    for (int i = 0; i < n1; i++)
      L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
      M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
      if (L[i] <= M[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = M[j];
        j++;
      }
      k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      arr[k] = M[j];
      j++;
      k++;
    }
  }

  // Divide the array into two subarrays, sort them and merge them
   public static void mergeSort(int arr[], int l, int r) {
    if (l < r) {

      // m is the point where the array is divided into two subarrays
      int m = (l + r) / 2;

      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);

      // Merge the sorted subarrays
      merge(arr, l, m, r);
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
            mergeSort(array, 0, array.length-1);
            endTime = System.nanoTime();

            tempo = (endTime - startTime) / 1e9;
            System.out.printf("%d -> tempo: %f -> tamanho: %d%n", i, tempo, tam);

            if (tempo < 60) {
                tam *= 10;
            }
        }
    }
}
