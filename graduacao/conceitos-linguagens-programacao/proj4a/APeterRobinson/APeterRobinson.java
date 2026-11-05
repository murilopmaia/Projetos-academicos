public class APeterRobinson {
    public static int A(int m, int n) {
        if (m == 0) {
            return n + 1;
        } else if (m > 0 && n == 0) {
            return A(m - 1, 1);
        } else if (m > 0 && n > 0) {
            return A(m - 1, A(m, n - 1));
        }
        return 0; // Isso nunca deve ser atingido
    }

    public static void main(String[] args) {
        System.out.println(A(5, 0)); // Exemplo de chamada da função
    }
}
