public class Ackerman {
    
    public static int A(int m, int n, int p) {
        if (p == 0) {
            return m + n;
        } else if (n == 0 && p == 1) {
            return 0;
        } else if (n == 0 && p == 2) {
            return 1;
        } else if (n == 0 && p > 2) {
            return m;
        } else if (n > 0 && p > 0) {
            return A(m, A(m, n - 1, p), p - 1);
        }
        return 0; 
    }
    
    public static void main(String[] args) {
        System.out.println(A(7, 5, 2)); 
    }
}