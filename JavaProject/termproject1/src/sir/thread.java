package sir;
import java.util.Scanner;


public class thread {
    public static void main(String[] args) {
        System.out.println();
        Scanner sc=new Scanner(System.in);
        int p=sc.nextInt();


        // System.out.println(Thread.activeCount());
        // System.out.println(Thread.currentThread());
        // Thread.currentThread().setName("MAIN");
        // System.out.println(Thread.currentThread().getName());
       // Thread.currentThread().setPriority(10);/* highest=10.lowest 0 */
       // System.out.println(Thread.currentThread().getPriority());
    //    System.out.println(Thread.currentThread());
    //     System.out.println(Thread.currentThread().isAlive());
 try{
       for(int i=0;i<4;i++){
           Thread.sleep(p);
        System.out.println(i);
     
    }
 }
 catch(Exception e){
    System.out.println(e);
 }
        System.out.println();
        sc.close();
    }

}
