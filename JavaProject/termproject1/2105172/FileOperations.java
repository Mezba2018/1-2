import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public class FileOperations {

    private static String INPUT_FILE_NAME;
    private static String OUTPUT_FILE_NAME;

    public static List<Restaurant> cRestaurant()
            throws Exception {
        INPUT_FILE_NAME = "restaurant.txt";
        List<Restaurant> restaurants = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader(INPUT_FILE_NAME));
        while (true) {
            String line = br.readLine();
            if (line == null)
                break;
            // System.out.println(line);
            String[] array = line.split(",", -1);
            int id = Integer.parseInt(array[0]);
            String name = array[1];
            double score = Double.parseDouble(array[2]);
            String price = array[3];
            String zipcode = array[4];
            String[] category = new String[3];
            for (int i = 5; i < array.length; i++) {
                category[i - 5] = array[i];
            }
            Restaurant restaurant = new Restaurant(id, name, score, price, zipcode, category);
            restaurants.add(restaurant);

            // for (int i = 0; i < array.length; i++) {
            // System.out.println(array[i]);
            // }
        }
        br.close();

        // String text = "Hello World";
        // BufferedWriter bw = new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME));
        // bw.write(text);
        // bw.write(System.lineSeparator());
        // bw.close();
        return restaurants;
    }

    public static List<Food> cFood()
            throws Exception {
        INPUT_FILE_NAME = "menu.txt";
        List<Food> foods = new ArrayList<>();
        BufferedReader br2 = new BufferedReader(new FileReader(INPUT_FILE_NAME));
        while (true) {
            String line = br2.readLine();
            if (line == null)
                break;
            // System.out.println(line);
            String[] array = line.split(",", -1);
            int restaurantid = Integer.parseInt(array[0]);
            String category = array[1];
            String name = array[2];
            double price = Double.parseDouble(array[3]);

            Food food = new Food(restaurantid, category, name, price);
            foods.add(food);

            // for (int i = 0; i < array.length; i++) {
            // System.out.println(array[i]);
            // }
        }
        br2.close();

        // String text = "Hello World";
        // BufferedWriter bw = new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME));
        // bw.write(text);
        // bw.write(System.lineSeparator());
        // bw.close();
        return foods;
    }

    /////////

    public static void writeRestaurants(String outputFile, List<Restaurant> restaurants) throws Exception {
        int count = 0, countFoodItem = restaurants.size();
        OUTPUT_FILE_NAME = outputFile;
        BufferedWriter bw = new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME));
        for (Restaurant tempRestaurant : restaurants) {
            String id = Integer.toString(tempRestaurant.getId());
            String name = tempRestaurant.getName();
            String score = Double.toString(tempRestaurant.getScore());
            String price = tempRestaurant.getPrice();
            String zipCode = tempRestaurant.getZipcode();
            String[] categories = tempRestaurant.getCategory();
            String line = id + "," + name + "," + score + "," + price + "," + zipCode;
            for (String tempCategory : categories)
                line += "," + tempCategory;
            if (categories.length != 3)
                line += ",";
            bw.write(line);
            count++;
            if (count != countFoodItem) {
                bw.write(System.lineSeparator());
            }
        }
        bw.close();

    }

    public static void writeMenu(String outputFile, List<Food> menu) throws Exception {
        int count = 0, countRestaurant = menu.size();
        OUTPUT_FILE_NAME = outputFile;
        BufferedWriter bw = new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME));
        for (Food tempFood : menu) {
            String id = Integer.toString(tempFood.getRestaurantId());
            String category = tempFood.getCategory();
            String name = tempFood.getName();
            String price = Double.toString(tempFood.getPrice());
            String line = id + "," + category + "," + name + "," + price;
            bw.write(line);
            count++;
            if (count != countRestaurant) {
                bw.newLine();
            }
        }
        bw.close();
    }

    ////////
}