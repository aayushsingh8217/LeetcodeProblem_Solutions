class FoodRatings {
private:
    unordered_map<string, string> food_to_cuisine;
    unordered_map<string, int> food_to_rating;
    map<string, set<pair<int, string>>> cuisine_to_rating_foods;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
          for (size_t i = 0; i < foods.size(); ++i) {
            const string& food = foods[i];
            const string& cuisine = cuisines[i];
            int rating = ratings[i];

            food_to_cuisine[food] = cuisine;
            food_to_rating[food] = rating;
            cuisine_to_rating_foods[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
    int old_rating = food_to_rating[food];
        const string& cuisine = food_to_cuisine[food];
        
        auto& food_set = cuisine_to_rating_foods[cuisine];
        food_set.erase({-old_rating, food});

        food_to_rating[food] = newRating;
        food_set.insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
 const auto& food_set = cuisine_to_rating_foods[cuisine];
        return food_set.begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */