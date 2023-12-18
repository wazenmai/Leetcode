/**
 * Title:  Design a Food Rating System (Leetcode Medium 2253)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, December, 2023
 * Method: Use priority_queue instead of vector.
 * Result: N = # of request, M = average # of food in a cuisine, C = # of cuisine, Time complexity: O(ClogM + NlogM)
 */

class Compare {
public:
    bool operator() (pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            int n = min(a.first.length(), b.first.length());
            for (int i = 0; i < n; i++) {
                if (a.first[i] == b.first[i])
                    continue;
                return a.first[i] > b.first[i];
            }
            return a.first.length() < b.first.length();
        }
        return a.second < b.second;
    }
};

class FoodRatings {
private:
    unordered_map<string, priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>> m;
    unordered_map<string, string> food2cuisine;
    unordered_map<string, int> foodRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            if (m.find(cuisines[i]) == m.end()) {
                m[cuisines[i]].push(make_pair(foods[i], ratings[i]));
            } else {
                m[cuisines[i]].push(make_pair(foods[i], ratings[i]));
            }
            food2cuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food2cuisine[food];
        foodRating[food] = newRating;
        m[cuisine].push(make_pair(food, newRating));
    }
    
    string highestRated(string cuisine) {
        while (!m[cuisine].empty()) {
            auto temp = m[cuisine].top();
            if (foodRating[temp.first] != temp.second) {
                m[cuisine].pop();
            } else {
                return temp.first;
            }
        }
        return m[cuisine].top().first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
