import java.util.ArrayList;
import java.util.List;
public class Restaurant {

    int id;
    String name;
    double score;
    String price;
    String zipcode;
    String[] category;

 List<Food> array = null;
  List<Food> recieve = null;

    
    
    // constructors

    // public Restaurant(int id, String name, double score, String price, String zipcode, String[] category) {
    //     this.id = id;
    //     this.name = name;
    //     this.score = score;
    //     this.price = price;
    //     this.zipcode = zipcode;
    //     this.category = category;
    // }
    public Restaurant(int id, String name, double score, String price, String zipcode, String[] category) {
        this.id = id;
        this.name = name;
        this.score = score;
        this.price = price;
        this.zipcode = zipcode;
        int i=0;
        for(i=0;i<3;i++){
            if(category[i].equals("-1"))break;
        }
        this.category = new String[i];
        for(int j=0;j<i; j++){
           // if (category[j]==null)continue;
            this.category[j] = category[j];
        }
        try {
      
        this.recieve = FileOperations.cFood();

    } catch (Exception e) {
        e.printStackTrace();
    }
    // for(int j=0;j<recieve.size();j++){
    //   if(  recieve.get(j).restaurantId==this.id){
    //     array.add(recieve.get(j));
    //   }
    // }
       this.array = new ArrayList<>();
    for(Food fud:recieve){
        if(fud.getRestaurantId()==this.id){
            this.array.add(fud);
        }
    }

    }

    // getters
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getScore() {
        return score;
    }

    public String getPrice() {
        return price;
    }

    public String getZipcode() {
        return zipcode;
    }

    public String[] getCategory() {
        return category;
    }
    public int getcount(){
        return array.size();
    }

    // show

    public void showDetails() {
        int count = 0;
        System.out.println("Restaurant ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Score: " + score);
        System.out.println("Price: " + price);
        System.out.println("Zip Code: " + zipcode);

        System.out.print("Categories: ");
        for (String cat : category) {

            System.out.print(cat);
            if (count < category.length) {
                System.out.print(",");
            } else {
                System.out.print(".");
            }
            count++;
        }
        System.out.println();
        System.out.println();
        System.out.println();
    }

    public void fsearchByName(String fname, List<Food> matchingfoods)
    {
          for (Food fud : array) {
            if (fud.getName().toLowerCase().contains(fname.toLowerCase())) {
                matchingfoods.add(fud);
            }
         }

    }
    public void fsearchByCategory(String fname, List<Food> matchingfoods)
    {
           for (Food fud : array) {
            if (fud.getCategory().toLowerCase().contains(fname.toLowerCase())) {
                matchingfoods.add(fud);
            }
        }

    }
     public void fsearchByPrice(double up,double down, List<Food> matchingfoods)
    {
        for (Food fud : array) {
            if (fud.getPrice() >= down && fud.getPrice() <= up) {
                matchingfoods.add(fud);
            }
        }

    }
      public void fcostliest(List<Food> matchingfoods)
    {
        double maxPrice = 0.0;
        for(Food fud:array){
            if(fud.getPrice()>maxPrice){
                maxPrice=fud.getPrice();
            }
        }
          for(Food fud:array){
            if(fud.getPrice()==maxPrice){
              matchingfoods.add(fud);
            }
        }

    }
    public int ftotalfood(){
        return getcount();
    }
    public boolean exist(Food f){
       for(Food fd:array){
        if (f.getName().equalsIgnoreCase(fd.getName()) && f.getCategory().equalsIgnoreCase(fd.getCategory())) {

                return false;

       }
    }
    this.array.add(f);
return true;
    }
}
