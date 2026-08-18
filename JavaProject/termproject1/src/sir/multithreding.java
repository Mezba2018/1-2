package sir;

class k1 extends Thread {

    @Override
    public void run() {
        System.out.println("thread1: executing");

        for (int i = 0; i <= 10; i++) {
            System.out.println("thread1:" + i);
            try {
                Thread.sleep(000);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }

}

class k2 implements Runnable {
    @Override
    public void run() {
        System.out.println("thread2: executing");

        for (int i = 10; i >= 0; i--) { // Change the loop condition to count down
            System.out.println("thread2:" + i);
            try {
                Thread.sleep(000);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }
}

public class multithreding {
    public static void main(String[] args) {
        k1 th1 = new k1();
        Runnable th = new k2();
        Thread th2 = new Thread(th);
        th1.start();
        th2.start();

    }

}
