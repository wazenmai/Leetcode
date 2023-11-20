/**
 * Title:  Minimum Amount of Time to Collect Garbage (Leetcode Medium 2391)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, November, 2023
 * Method: Use function to calculate the time for each garbage type
 * Result: Time complexity O(3n) = O(n), space complexity O(1)
 */

class Solution {
public:
    int n;
    int truck(vector<string>& garbage, vector<int>& travel, char g) {
        int time = 0;
        int accumulated = 0;
        for (int i = 0; i < n; i++) {
            bool appear = false;
            for (char& c: garbage[i]) {
                if (c == g) {
                    appear = true;
                    time += 1;
                }
            }
            if (appear) {
                time += accumulated;
                if (i < n - 1) accumulated = travel[i];
            } else if (i < n - 1) {
                accumulated += travel[i];
            }
        }
        return time;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        n = garbage.size();
        return truck(garbage, travel, 'M') + truck(garbage, travel, 'G') + truck(garbage, travel, 'P');        
    }
};
