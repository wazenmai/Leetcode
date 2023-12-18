/**
 * Title:  Design a Food Rating System (Leetcode Medium 2253)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, December, 2023
 * Method: Use unordered_map to store cusine: vector of pair<food, rating> and another unordered_map to store food: cuisine
 * Result: TLE. N = # of request, M = average # of food in a cuisine, C = # of cuisine, Time complexity: O(CMlogM + NMlogM)
 */

class FoodRatings {
private:
    unordered_map<string, vector<pair<string, int>>> m;
    unordered_map<string, string> food2cuisine;
    static bool my_compare(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            int n = min(a.first.length(), b.first.length());
            for (int i = 0; i < n; i++) {
                if (a.first[i] == b.first[i])
                    continue;
                return a.first[i] < b.first[i];
            }
            return a.first.length() > b.first.length();
        }
        return a.second > b.second;
    }
    void printFood() {
        for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->first << ": ";
            for (auto& p: it->second) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << "\n";
        }
    }

    void printCuisine(string cuisine) {
        cout << cuisine << ": ";
        for (auto& p: m[cuisine]) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "\n";
    }

    void sortAll() {
        for (auto it = m.begin(); it != m.end(); it++) {
            sort(it->second.begin(), it->second.end(), my_compare);
        }
    }

    void sortCuisine(string cuisine) {
        sort(m[cuisine].begin(), m[cuisine].end(), my_compare);
    }
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            if (m.find(cuisines[i]) == m.end()) {
                vector<pair<string, int>> v;
                v.emplace_back(make_pair(foods[i], ratings[i]));
                m[cuisines[i]] = v;
            } else {
                m[cuisines[i]].emplace_back(make_pair(foods[i], ratings[i]));
            }
            food2cuisine[foods[i]] = cuisines[i];
        }
        sortAll();
        // printFood();
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food2cuisine[food];
        for (auto& p: m[cuisine]) {
            if (p.first == food) {
                p.second = newRating;
            }
        }
        sortCuisine(cuisine);
        // printCuisine(cuisine);
    }
    
    string highestRated(string cuisine) {
        return m[cuisine][0].first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
