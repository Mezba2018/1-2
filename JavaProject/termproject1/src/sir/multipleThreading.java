package sir;

class normal extends Thread {
    @Override
    public void run() {
        System.out.println("enter nomal");
        for (int i = 0; i <= 10; i++) {
            System.out.println("Normal: " + i);

            try {
                Thread.sleep(1000);

            } catch (Exception e) {
                System.out.println(e);
            }

        }

        System.out.println("exit nomal");

    }
}

class Run implements Runnable {
    @Override
    public void run() {
        // System.out.println();
        System.out.println("enter Run");
        for (int i = 10; i >= 0; i--) {
            System.out.println("Run: " + i);

            try {
                Thread.sleep(1000);

            } catch (Exception e) {
                System.out.println(e);
            }
        }

        System.out.println("exit Run");

    }
}

public class multipleThreading {
    public static void main(String[] args) throws Exception {
        normal t1 = new normal();
        Runnable x = new Run();
        Thread t2 = new Thread(x);

        t1.start();
        t1.join(3000);
        t2.start();

        // System.out.println(1/0);

    }

}
