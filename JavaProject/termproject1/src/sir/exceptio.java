package sir;

public class exceptio {
    public static void main(String[] args) {
        int a=10,b=3;
        try{
          int  c=a/b;
          System.out.println(c);
            System.out.println("now print");
        }
        catch(Exception e){
            System.out.println("in catch");
            System.out.println(e);

        }
        finally{
            System.out.println("Always execute");
        }
    }
    // try{}
    // catch{}
    // throw{}
    // throws{}
    // finally{}
    
}
