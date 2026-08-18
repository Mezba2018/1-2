import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class RestaurantManagement {
    private List<Restaurant> restaurantarray;
    private List<Food> foodarray;

    RestaurantManagement(List<Restaurant> restaurants, List<Food> foods) {
        // this.restaurantarray=new ArrayList<>();
        // this.foodarray= new ArrayList<>();
        this.restaurantarray = restaurants;
        this.foodarray = foods;
    }

    public void addRestaurant(Restaurant r) {
        restaurantarray.add(r);

    }

    public boolean addFood(Food f) {
        boolean isUnique=false;
        for(Restaurant res:restaurantarray){
            if(f.getRestaurantId()==res.getId()){
              isUnique=res.exist(f);
              break;
            }
        }
        // for (Food fd : foodarray) {
        //     if (f.getName().equalsIgnoreCase(fd.getName()) && f.getCategory().equalsIgnoreCase(fd.getCategory())
        //             && fd.getRestaurantId() == f.getRestaurantId()) {

        //         isUnique = false;
        //         break;
        //     }
        // }
        if (isUnique) {
            foodarray.add(f);
        }

        return isUnique;

    }

    /* restaurants */
    // 1
    public List<Restaurant> rsearchbyName(String resname) {
        List<Restaurant> matchingRestaurants = new ArrayList<>();

        for (Restaurant res : restaurantarray) {
            if (resname.equalsIgnoreCase(res.getName())) {
                matchingRestaurants.add(res);
            }
        }
        return matchingRestaurants;
    }

    // my need
    public List<Restaurant> rfindbyName(String resname) {
        List<Restaurant> matchingRestaurants = new ArrayList<>();

        for (Restaurant res : restaurantarray) {
            if (res.getName().toLowerCase().contains(resname.toLowerCase())) {
                matchingRestaurants.add(res);
            }
        }
        return matchingRestaurants;
    }

    // 2
    public List<Restaurant> rsearchbyScore(double up, double down) {
        List<Restaurant> matchingRestaurants = new ArrayList<>();

        for (Restaurant res : restaurantarray) {
            if (res.getScore() >= down && res.getScore() <= up) {
                matchingRestaurants.add(res);
            }
        }
        return matchingRestaurants;

    }

    // 3
    public List<Restaurant> rsearchbyCategory(String cat) {
        List<Restaurant> matchingRestaurants = new ArrayList<>();

        for (Restaurant res : restaurantarray) {
            // int count=0;
            for (String category : res.getCategory()) {

                if (cat.equalsIgnoreCase(category)) {
                    matchingRestaurants.add(res);
                    // count=1;
                }
            }
        }
        return matchingRestaurants;
    }

    // my need
    public List<Restaurant> rfindbyCategory(String cat) {
        List<Restaurant> matchingRestaurants = new ArrayList<>();

        for (Restaurant res : restaurantarray) {
            try {
                for (String category : res.getCategory()) {
                    if (category.toLowerCase().contains(cat.toLowerCase())) {
                        matchingRestaurants.add(res);
                        break;
                    }

                }
            } catch (Exception e) {
            }
        }
        return matchingRestaurants;
    }

    // 4
    public List<Restaurant> rsearchbyPrice(String price) {
        List<Restaurant> matchingRestaurants = new ArrayList<>();

        for (Restaurant res : restaurantarray) {
            if (price.equals(res.getPrice())) {
                matchingRestaurants.add(res);
            }
        }
        return matchingRestaurants;
    }

    // 5
    public List<Restaurant> rsearchbyZip(String zip) {
        List<Restaurant> matchingRestaurants = new ArrayList<>();

        for (Restaurant res : restaurantarray) {
            if (zip.equals(res.getZipcode())) {
                matchingRestaurants.add(res);
            }
        }
        return matchingRestaurants;
    }

    // my need
    public List<Restaurant> rsearchbyID(int id) {
        List<Restaurant> matchingRestaurants = new ArrayList<>();
        for (Restaurant res : restaurantarray) {
            if (id == res.getId()) {
                matchingRestaurants.add(res);
            }
        }
        return matchingRestaurants;

    }

    public Map<String, List<String>> displayCategoryWiseRestaurants() {
        System.out.println("Category-wise Restaurant Names:");
    
        // Create a map to store categories and corresponding restaurant names
        Map<String, List<String>> categoryRestaurantMap = new HashMap<>();
    
        // Populate the map with restaurant names based on categories
        for (Restaurant res : restaurantarray) {
            for (String category : res.getCategory()) {
                if (!category.isEmpty()) {
                    String lowercaseCategory = category.toLowerCase();
                    categoryRestaurantMap.computeIfAbsent(lowercaseCategory, k -> new ArrayList<>())
                            .add(res.getName().toLowerCase());
                }
            }
        }
        return categoryRestaurantMap;
    }
    
    public void displayCategoryWiseRestaurantsOutput(Map<String, List<String>> categoryRestaurantMap) {
        for (Map.Entry<String, List<String>> entry : categoryRestaurantMap.entrySet()) {
            String category = entry.getKey();
            List<String> restaurantNames = entry.getValue();
    
            System.out.println(category + ": " + String.join(", ", restaurantNames));
        }
    }
    

    // 6to do
    // public Map<String, List<String>> displayCategoryWiseRestaurants() {
    // System.out.println("Category-wise Restaurant Names:");

    // // Create a map to store categories and corresponding restaurant names
    // Map<String, List<String>> categoryRestaurantMap = new HashMap<>();

    // // Populate the map with restaurant names based on categories
    // for (Restaurant res : restaurantarray) {
    // for (String category : res.getCategory()) {
    // if (!category.isEmpty()) {
    // categoryRestaurantMap.computeIfAbsent(category, k -> new
    // ArrayList<>()).add(res.getName().toLowerCase());
    // }
    // }
    // }
    // return categoryRestaurantMap;
    // }
    // public Map<String, List<String>> displayCategoryWiseRestaurants() {
    //     System.out.println("Category-wise Restaurant Names:");

    //     // Create a map to store categories and corresponding restaurant names
    //     Map<String, List<String>> categoryRestaurantMap = new HashMap<>();

    //     // Populate the map with restaurant names based on categories
    //     for (Restaurant res : restaurantarray) {
    //         for (String category : res.getCategory()) {
    //             boolean check = true;
    //             for (Map.Entry<String, List<String>> entry : categoryRestaurantMap.entrySet()) {
    //                 String tempCategory = entry.getKey();
    //                 if (tempCategory.toLowerCase().equals(category.toLowerCase()))
    //                     check = false;
    //             }
    //             if (check) {
    //                 categoryRestaurantMap.computeIfAbsent(category, k -> new ArrayList<>())
    //                         .add(res.getName().toLowerCase());
    //             }
    //         }
    //     }
    //     return categoryRestaurantMap;
    // }

    // public void displayCategoryWiseRestaurantsOutput(Map<String, List<String>> categoryRestaurantMap) {
    //     for (Map.Entry<String, List<String>> entry : categoryRestaurantMap.entrySet()) {
    //         String category = entry.getKey();
    //         List<String> restaurantNames = entry.getValue();

    //         System.out.println(category + ": " + String.join(", ", restaurantNames));
    //     }

    // }

    // // Print the category-wise restaurant names
    // for (Map.Entry<String, List<String>> entry :
    // categoryRestaurantMap.entrySet()) {
    // String category = entry.getKey();
    // List<String> restaurantNames = entry.getValue();

    // System.out.println(category + ": " + String.join(", ", restaurantNames));
    // }
    // }

    public int getRestaurantCount() {
        return restaurantarray.size();
    }

    /* food */

    // 1
    // public List<Food> fsearchbyName(String fname) {
    //     List<Food> matchingfoods = new ArrayList<>();

    //     for (Food fud : foodarray) {
    //         if (fname.equalsIgnoreCase(fud.getName())) {
    //             matchingfoods.add(fud);
    //         }
    //     }
    //     return matchingfoods;
    // }

    // my need

    public List<Food> ffindbyName(String fname) {

        List<Food> matchingfoods = new ArrayList<>();
        // for (Food fud : foodarray) {
        //     if (fud.getName().toLowerCase().contains(fname.toLowerCase())) {
        //         matchingfoods.add(fud);
        //     }
        // }
        for(Restaurant res:restaurantarray){
            res.fsearchByName(fname, matchingfoods);
        }
        return matchingfoods;

    }

    // 2
    public List<Food> fsearchbyNameInRestaurant(String foodName, String restaurantName) {
        List<Food> matchingFoods = new ArrayList<>();

        // for (Food food : foodarray) {
        //     if (food.getName().toLowerCase().contains(foodName.toLowerCase())) {
        //         int restaurantId = food.getRestaurantId();
        //         for (Restaurant restaurant : restaurantarray) {
        //             if (restaurant.getName().equalsIgnoreCase(restaurantName) && restaurant.getId() == restaurantId) {
        //                 matchingFoods.add(food);
        //                 break;
        //             }
        //         }
        //     }
        // }
         for (Restaurant restaurant : restaurantarray) {
                    if (restaurant.getName().equalsIgnoreCase(restaurantName) ) {
                       restaurant.fsearchByName(foodName, matchingFoods);
                        break;
                    }
                }
        return matchingFoods;
    }

    // 3
    // public List<Food> fsearchbyCategory(String fname) {
    //     List<Food> matchingfoods = new ArrayList<>();

    //     for (Food fud : foodarray) {

    //         if (fname.equalsIgnoreCase(fud.getCategory())) {
    //             matchingfoods.add(fud);

    //         }
    //     }
    //     return matchingfoods;
    // }

    // my need
    public List<Food> ffindbyCategory(String fname) {
        List<Food> matchingfoods = new ArrayList<>();

        // for (Food fud : foodarray) {
        //     if (fud.getCategory().toLowerCase().contains(fname.toLowerCase())) {
        //         matchingfoods.add(fud);
        //     }
        // }
         for(Restaurant res:restaurantarray){
            res.fsearchByCategory(fname, matchingfoods);
        }
        return matchingfoods;
    }

    // 4
    public List<Food> fsearchbyCategoryInRestaurant(String category, String restaurantName) {
        List<Food> matchingFoods = new ArrayList<>();

        // for (Food food : foodarray) {
        //     if (food.getCategory().toLowerCase().contains(category.toLowerCase())) {
        //         int restaurantId = food.getRestaurantId();
        //         for (Restaurant restaurant : restaurantarray) {
        //             if (restaurant.getName().equalsIgnoreCase(restaurantName) && restaurant.getId() == restaurantId) {
        //                 matchingFoods.add(food);
        //                 break;
        //             }
        //         }
        //     }
        // }
          for (Restaurant restaurant : restaurantarray) {
                    if (restaurant.getName().equalsIgnoreCase(restaurantName)) {
                        restaurant.fsearchByCategory(category, matchingFoods);
                        break;
                    }
                }
        return matchingFoods;
    }

    // 5
    public List<Food> fsearchbyPrice(double up, double down) {
        List<Food> matchingfoods = new ArrayList<>();

        // for (Food res : foodarray) {
        //     if (res.getPrice() >= down && res.getPrice() <= up) {
        //         matchingfoods.add(res);
        //     }
        // }
          
   for(Restaurant res:restaurantarray){
         res.fsearchByPrice(up, down, matchingfoods);
        }
        
        return matchingfoods;

    }

    // 6
    // 6) By Price Range in a Given Restaurant
    public List<Food> fsearchbyPriceRangeInRestaurant(double maxPrice, double minPrice, String restaurantName) {
        List<Food> matchingFoods = new ArrayList<>();

        // for (Food food : foodarray) {
        //     if (food.getPrice() >= minPrice && food.getPrice() <= maxPrice) {
        //         int restaurantId = food.getRestaurantId();
        //         for (Restaurant restaurant : restaurantarray) {
        //             if (restaurant.getName().equalsIgnoreCase(restaurantName) && restaurant.getId() == restaurantId) {
        //                 matchingFoods.add(food);

        //                 break;
        //             }
        //         }
        //     }
        // }
         for (Restaurant restaurant : restaurantarray) {
                    if (restaurant.getName().equalsIgnoreCase(restaurantName) ) {
                 restaurant.fsearchByPrice(maxPrice, minPrice, matchingFoods);
                        break;
                    }
                }
        return matchingFoods;
    }

    // 7

    public List<Food> costliestFoodInRestaurant(String restaurantName) {
        List<Food> costliestFoods = new ArrayList<>();
      //  double maxPrice = 0.0;

        for (Restaurant restaurant : restaurantarray) {
            if (restaurant.getName().equalsIgnoreCase(restaurantName)) {
                restaurant.fcostliest(costliestFoods);
                // int restaurantId = restaurant.getId();
                // for (Food food : foodarray) {
                //     if (food.getRestaurantId() == restaurantId && food.getPrice() > maxPrice) {
                //         maxPrice = food.getPrice();
                //     }
                // }
                // for (Food food : foodarray) {
                //     if (food.getRestaurantId() == restaurantId && food.getPrice() == maxPrice) {
                //         costliestFoods.add(food);
                //     }
                // }
                // break;
            }
        }
        return costliestFoods;
    }

    // 8
    public void totalFoodItemsPerRestaurant() {
        System.out.println("List of Restaurants and Total Food Items on the Menu:");
        for (Restaurant restaurant : restaurantarray) {
           // int num=restaurant.ftotalfood();
             System.out.println(restaurant.getName() + ": " + restaurant.ftotalfood());

            // int restaurantId = restaurant.getId();
            // int totalFoodItems = 0;

            // for (Food food : foodarray) {
            //     if (food.getRestaurantId() == restaurantId) {
            //         totalFoodItems++;
            //     }
            // }

            // System.out.println(restaurant.getName() + ": " + totalFoodItems);
        }
    }

    void rshowDetails(List<Restaurant> r) {
        if (r.isEmpty()) {
            System.out.println("No such restaurent");
        } else {
            for (int i = 0; i < r.size(); i++) {
                r.get(i).showDetails();
            }
        }

    }

    void fshowDetails(List<Food> r) {
        if (r.isEmpty()) {
            System.out.println("No such food");
        } else {
            for (int i = 0; i < r.size(); i++) {
                r.get(i).showDetails();
            }
        }

    }

    public List<Food> getMenu() {
        return foodarray;

    }

    public List<Restaurant> getRestaurant() {
        return restaurantarray;

    }

    // main ends
}
