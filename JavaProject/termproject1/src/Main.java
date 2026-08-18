import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        List<Restaurant> restaurants = null;
        List<Food> foods = null;
        try {
            restaurants = FileOperations.cRestaurant();
            foods = FileOperations.cFood();

        } catch (Exception e) {
            e.printStackTrace();
        }

        RestaurantManagement restaurantManagement = new RestaurantManagement(restaurants, foods);
        Scanner scanner = new Scanner(System.in);
        int outcheck;

        do {
            System.out.println("Main Menu");
            System.out.println("1) Search Restaurants");
            System.out.println("2) Search Food Items");
            System.out.println("3) Add Restaurant");
            System.out.println("4) Add Food Item to the Menu");
            System.out.println("5) Exit System");
            System.out.print("Option: ");

            outcheck = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (outcheck) {
                case 1:
                    // Handle Search Restaurants
                    // searchRestaurants(scanner);
                    boolean ck = true;
                    while (ck) {
                        System.out.println("Restaurant Searching Options:");
                        System.out.println("1) By Name");
                        System.out.println("2) By Score");
                        System.out.println("3) By Category");
                        System.out.println("4) By Price");
                        System.out.println("5) By Zip Code");
                        System.out.println("6) Different Category Wise List of Restaurants");
                        System.out.println("7) Back to Main Menu");

                        System.out.print("Option: ");
                        int search = scanner.nextInt();
                        scanner.nextLine(); // Consume newline

                        // Implement different search options based on searchOption here
                        switch (search) {
                            case 1:
                                System.out.print("Restaurent name: ");
                                String name = scanner.nextLine();
                                List<Restaurant> nameres = restaurantManagement.rfindbyName(name);
                                restaurantManagement.rshowDetails(nameres);

                                // Implement search by name
                                break;

                            case 2:
                                // Implement search by score range
                                System.out.print("lower range: ");
                                double down = scanner.nextDouble();
                                System.out.print("upper range: ");
                                double up = scanner.nextDouble();
                                List<Restaurant> scoreres = restaurantManagement.rsearchbyScore(up, down);
                                restaurantManagement.rshowDetails(scoreres);

                                break;

                            case 3:
                                // Implement search by category
                                System.out.print("category: ");
                                String category = scanner.nextLine();
                                List<Restaurant> catres = restaurantManagement.rfindbyCategory(category);
                                restaurantManagement.rshowDetails(catres);

                                break;

                            case 4:
                                // Implement search by price
                                System.out.print("Price: ");
                                String price = scanner.nextLine();
                                List<Restaurant> priceres = restaurantManagement.rsearchbyPrice(price);
                                restaurantManagement.rshowDetails(priceres);

                                break;

                            case 5:
                                // Implement search by zip code
                                System.out.print("Zip: ");
                                String zip = scanner.nextLine();
                                List<Restaurant> zipres = restaurantManagement.rsearchbyZip(zip);
                                restaurantManagement.rshowDetails(zipres);

                                break;

                            case 6:
                                // Implement different category wise list
                                Map<String, List<String>> categoryRestaurantMap = restaurantManagement. displayCategoryWiseRestaurants();
                                restaurantManagement.displayCategoryWiseRestaurantsOutput(categoryRestaurantMap);

                                break;

                            case 7:
                                // Go back to the main menu
                                ck = false;
                                break;

                            default:
                                System.out.println("Invalid option. Please choose again.");
                                break;
                        }
                    }
                    break;

                case 2:
                    // Handle Search Food Items
                    // searchFood(scanner);
                    boolean check = true;
                    while (check) {

                        System.out.println("Food Item Searching Options:");
                        System.out.println("1) By Name");
                        System.out.println("2) By Name in a Given Restaurant");
                        System.out.println("3) By Category");
                        System.out.println("4) By Category in a Given Restaurant");
                        System.out.println("5) By Price Range");
                        System.out.println("6) By Price Range in a Given Restaurant");
                        System.out.println("7) Costliest Food Item(s) on the Menu in a Given Restaurant");
                        System.out.println("8) List of Restaurants and Total Food Items on the Menu");
                        System.out.println("9) Back to Main Menu");

                        System.out.print("Option: ");
                        int searchOption = scanner.nextInt();
                        scanner.nextLine(); // Consume newline

                        switch (searchOption) {
                            case 1:
                                // Search by Name
                                System.out.print("name: ");
                                String name = scanner.nextLine();
                                List<Food> namefd = restaurantManagement.ffindbyName(name);
                                restaurantManagement.fshowDetails(namefd);

                                // Implement search by name logicS
                                break;

                            case 2:
                                // Search by Name in a Given Restaurant
                                System.out.print("food name: ");
                                String fname = scanner.nextLine();
                                System.out.print("restaurant name: ");
                                String rname = scanner.nextLine();
                                List<Food> nameresfd = restaurantManagement.fsearchbyNameInRestaurant(fname, rname);
                                restaurantManagement.fshowDetails(nameresfd);

                                // Implement search by name in restaurant logic
                                break;

                            case 3:
                                System.out.print("category: ");
                                String category = scanner.nextLine();
                                // Search by Category
                                List<Food> catfd = restaurantManagement.ffindbyCategory(category);
                                restaurantManagement.fshowDetails(catfd);

                                // Implement search by category logic
                                break;

                            case 4:
                                // Search by Category in a Given Restaurant
                                System.out.print("category: ");
                                String categoryName = scanner.nextLine();
                                System.out.print("restaurant name: ");
                                String restaurantName = scanner.nextLine();
                                List<Food> catfdinres = restaurantManagement.fsearchbyCategoryInRestaurant(categoryName,
                                        restaurantName);
                                restaurantManagement.fshowDetails(catfdinres);

                                // Implement search by category in restaurant logic
                                break;

                            case 5:
                                System.out.print("lower range: ");
                                double down = scanner.nextDouble();
                                System.out.print("upper range: ");
                                double up = scanner.nextDouble();
                                List<Food> pricefd = restaurantManagement.fsearchbyPrice(up, down);
                                restaurantManagement.fshowDetails(pricefd);

                                // Implement search by price range logic
                                break;

                            case 6:
                                System.out.print("lower range: ");
                                double downer = scanner.nextDouble();
                                System.out.print("upper range: ");
                                double upper = scanner.nextDouble();
                                System.out.print("restaurant name: ");
                                String resName = scanner.nextLine();
                                List<Food> pricefdinres = restaurantManagement.fsearchbyPriceRangeInRestaurant(upper,
                                        downer, resName);
                                restaurantManagement.fshowDetails(pricefdinres);

                                // Implement search by price range in restaurant logic
                                break;

                            case 7:
                                // Costliest Food Item(s) on the Menu in a Given Restaurant
                                System.out.print("restaurant name: ");
                                String restName = scanner.nextLine();
                                List<Food> costfd = restaurantManagement.costliestFoodInRestaurant(restName);
                                restaurantManagement.fshowDetails(costfd);

                                // Implement costliest food item logic
                                break;

                            case 8:
                                // List of Restaurants and Total Food Items on the Menu
                                // Implement list of restaurants and total food items logic
                                restaurantManagement.totalFoodItemsPerRestaurant();
                                break;

                            case 9:
                                // Go back to the main menu
                                check = false;
                                break;

                            default:
                                System.out.println("Invalid option. Please choose again.");
                                break;
                        }

                    }

                    break;

                case 3:

                    // Handle Add Restaurant
                    System.out.println("Adding a New Restaurant");
                    System.out.print("Enter Restaurant Name: ");
                    String name = scanner.nextLine();
                    List<Restaurant> exists = restaurantManagement.rsearchbyName(name);
                    if (!exists.isEmpty()) {
                        System.out.println("Already exists such restaurant with the provided name.");
                        break;
                    }

                    // boolean chk=true;

                    // System.out.print("Enter Restaurant ID: ");
                    int id = restaurantManagement.getRestaurantCount() + 1;
                    // scanner.nextLine(); // Consume newline
                    // while(chk){
                    // List<Restaurant> existing=restaurantManagement.rsearchbyID(id);
                    // if(!existing.isEmpty()){
                    // System.out.println("Already exists such restaurant with the provided ID,you
                    // need an unique one.");
                    // System.out.print("Enter Restaurant ID again: ");
                    // id = scanner.nextInt();
                    // scanner.nextLine();
                    // }
                    // else{
                    // chk=false;
                    // }

                    // }

                    System.out.print("Enter Restaurant Score: ");
                    double score = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline

                    System.out.print("Enter Restaurant Price: ");
                    String price = scanner.nextLine();

                    System.out.print("Enter Restaurant Zip Code: ");
                    String zipcode = scanner.nextLine();

                    System.out.print("Enter Number of Categories: ");
                    int numCategories = scanner.nextInt();
                    scanner.nextLine(); // Consume newline

                    String[] categories = new String[3];
                    for (int i = 0; i < numCategories; i++) {
                        System.out.print("Enter Category " + (i + 1) + ": ");
                        categories[i] = scanner.nextLine();
                    }
                    for (int i = numCategories; i < categories.length; i++) {
                        categories[i] = "-1";
                    }
                    
                  //  System.out.println(categories.length);

                    Restaurant newRestaurant = new Restaurant(id, name, score, price, zipcode, categories);
                    restaurantManagement.addRestaurant(newRestaurant);
                    System.out.println("New restaurant added successfully");

                    break;

                case 4:
                    // Handle Add Food Item to the Menu
                    System.out.println("Adding a Food Item to a Restaurant's Menu");
                    System.out.print("Enter Restaurant Name: ");
                    String restaurantName = scanner.nextLine();
                    List<Restaurant> exist = restaurantManagement.rsearchbyName(restaurantName);
                    if (exist.isEmpty()) {
                        System.out.println("No such restaurant with the provided name.");
                        break;
                    }
                    System.out.print("Enter Food Item Name: ");
                    String foodName = scanner.nextLine();

                    System.out.print("Enter Food Item Category: ");
                    String foodCategory = scanner.nextLine();

                    System.out.print("Enter Food Item Price: ");
                    double foodPrice = scanner.nextDouble();
                    scanner.nextLine(); // Consume newline

                    // Create a new Food object and add it to the foodarray list
                    Food newFoodItem = new Food(exist.get(0).getId(), foodCategory, foodName, foodPrice);
                    boolean x = restaurantManagement.addFood(newFoodItem);
                    if (x) {
                        System.out.println("New food added successfully");
                    } else {
                        System.out.println("already exists the provided food.");

                    }

                    break;

                case 5:
                    // Exit the loop and the program
                    try {
                        FileOperations.writeMenu("menu.txt", restaurantManagement.getMenu());
                        FileOperations.writeRestaurants("restaurant.txt", restaurantManagement.getRestaurant());

                    } catch (Exception e) {

                    }
                    break;

                default:
                    System.out.println("Invalid option. Please choose again.");
                    break;
            }

        } while (outcheck != 5);

        // Close the scanner when done
        scanner.close();
    }

    // public static void searchRestaurants(Scanner scanner) {

    // }

    // public static void searchFood(Scanner scanner){

    // }

    // Main ends here
}