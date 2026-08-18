public class Restaurant {

    int id;
    String name;
    double score;
    String price;
    String zipcode;
    String[] category;

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
        int i;
        for(i=0;i<3;i++){
            if(category[i].equals(""))break;
        }
        this.category = new String[i];
        for(int j=0;j<i; j++){
            this.category[j] = category[j];
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

}
