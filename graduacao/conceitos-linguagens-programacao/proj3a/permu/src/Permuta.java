import java.util.Arrays;

public class Permuta {
    
    public static void troca(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    public static void permuta(int[] array, int start, int end) {
        if (start != end) {
            for (int i = start; i <= end; i++) {
                troca(array, start, i);
                permuta(array, start + 1, end);
                troca(array, start, i); // backtracking
            }
        }
    }
    
    public static void main(String[] args) {
        int n = 0;
        int[] v = new int[50];
        long ini, fim;
        double tempo = 0.0;
        while (tempo < 70.0) {
            v[n] = n;
            n++;
            ini = System.currentTimeMillis();
            permuta(v, 0, n - 1);
            fim = System.currentTimeMillis();
            tempo = (fim - ini) / 1000.0;
            System.out.println("n = " + n + ", tempo = " + tempo);
        }
    }
}
