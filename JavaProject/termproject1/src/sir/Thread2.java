package sir;

public class Thread2 implements Runnable{
   
   @Override
     public void run() {
        System.out.println("Thread3: executing");

        for (int i = 10; i >= 0; i--) { // Change the loop condition to count down
            System.out.println("Thread2:" + i);
            try{
                Thread.sleep(500);
            }
            catch(Exception e){
                System.out.println(e);
            }
        }
    }

}

class test {
    public static void main(String[] args) {
        Runnable  th=new Thread2 ();
       Thread th2=new Thread(th);
       th2.start();
       
    }
    
}
