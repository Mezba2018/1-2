package sir;

public class exception2 {
    public static void main(String[] args) {
        int a = 10;
        int c = 0;
        for (int i = 0; i < 10; i++) {
            try {
                if (i == 6)
                    c = a % (i - 6);

                c = a % i;

            } catch (Exception e) {
                c = -1;
                System.out.println(e);

            } finally {
                System.out.println(c);

            }
        }
    }
}
