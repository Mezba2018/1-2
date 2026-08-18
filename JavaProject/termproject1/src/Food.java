public class Food {
    String name;
    String category;
    double price;
    int restaurantId;

    // constructor

    public Food(int restaurantId, String category, String name, double price) {
        this.restaurantId = restaurantId;
        this.category = category;
        this.name = name;
        this.price = price;

    }

    // getters

    public String getName() {
        return name;
    }

    public String getCategory() {
        return category;
    }

    public double getPrice() {
        return price;
    }

    public int getRestaurantId() {
        return restaurantId;
    }

    // show

    public void showDetails() {
        System.out.println("Food Name: " + name);

        System.out.println("Categories: " + category);

        System.out.println("Price: " + price);
        System.out.println("Restaurant ID: " + restaurantId);
        System.out.println();
        System.out.println();
        System.out.println();
    }

}
