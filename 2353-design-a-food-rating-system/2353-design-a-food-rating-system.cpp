class FoodRatings {
private:
    unordered_map<string, pair<int, string>> foodRating;      // {food, {}rating,cuisine}}
    unordered_map<string, set<pair<int, string>>> cuisineFood;      // {cuisine, set{rating,food}}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++)
        {
            foodRating[foods[i]] = {ratings[i], cuisines[i]};
            cuisineFood[cuisines[i]].insert({ -ratings[i], foods[i] }); // minus(-) rating to sort in increasing order, ~ editorial idea
        }
    }
    
    void changeRating(string food, int newRating) {
        if(foodRating.find(food) == foodRating.end())
            return;
        
        int oldRating = foodRating[food].first;
        string cuisine = foodRating[food].second;
        auto it = cuisineFood[cuisine].find({ -oldRating, food});
        cuisineFood[cuisine].erase(it);

        foodRating[food].first = newRating;
        cuisineFood[cuisine].insert({ -newRating, food });
    }
    
    string highestRated(string cuisine) {
        if(cuisineFood.find(cuisine) == cuisineFood.end())
            return "";

        auto maxRat = *cuisineFood[cuisine].begin();
        return maxRat.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */