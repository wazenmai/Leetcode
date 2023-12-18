/**
 * Title:  Design a Food Rating System (Leetcode Medium 2253)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, December, 2023
 * Method: Use set to store <food, rating>
 * Result: N = # of request, M = average # of food in a cuisine, C = # of cuisine, Time complexity: O(CM + NM)
 */

struct cmp {
    bool operator() (const pair<string, int>& a, const pair<string, int>& b) const {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};

class FoodRatings {
private:
    unordered_map<string, set<pair<string, int>, cmp>> m; // cusine: <food, rating>
    unordered_map<string, pair<string, int>> foodInfo; // food: <cusine, rating>

    void printset(string cuisine) {
        cout << cuisine << ": ";
        for (auto it = m[cuisine].begin(); it != m[cuisine].end(); it++) {
            cout << "(" << it->first << ", " << it->second << ") ";
        }
        cout << "\n";
    }

    void printall() {
        for (auto iterator = m.begin(); iterator != m.end(); iterator++) {
            printset(iterator->first);
        }
    }
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int n = foods.size();
        for (int i = 0; i < n; i++) {
            m[cuisines[i]].insert(make_pair(foods[i], ratings[i]));
            foodInfo[foods[i]] = make_pair(cuisines[i], ratings[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto temp = foodInfo[food];
        m[temp.first].erase({food, temp.second});
        m[temp.first].insert(make_pair(food, newRating));
        foodInfo[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        return m[cuisine].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
