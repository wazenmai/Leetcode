/**
 * Title:  Sort Integers by The Number of 1 Bits (Leetcode Easy 1356)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, October, 2023
 * Method: First we count the number of 1 bits of each number and put it in corresponding array. Then we sort each array and put them in the answer array.
 * Result: Time Complexity O(nlogn), Space Complexity O(n)
 */

class Solution {
public:
    void print(vector<vector<int>>& v) {
        for (int i = 0; i < 15; i++) {
            if (v[i].empty()) continue;
            cout << i << " bits: ";
            for (int& e: v[i]) {
                cout << e << " ";
            }
            cout << "\n";
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> ones(15);
        for (int& num: arr) {
            int temp = num;
            int one = 0;
            while (temp > 0) {
                if (temp & 1) one++;
                temp /= 2;
            }
            ones[one].emplace_back(num);
        }
        // print(ones);
        vector<int> ans;
        for (int i = 0; i < 15; i++) {
            if (ones[i].empty()) continue;
            sort(ones[i].begin(), ones[i].end());
            for (int& e: ones[i]) {
                ans.emplace_back(e);
            }
        }
        return ans;
    }
};
