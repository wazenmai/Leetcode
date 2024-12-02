/**
 * Title:  Check If N and Its Double Exist (Leetcode Easy 1346)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, December, 2024
 * Result: Time complexity O(n). Space complexity O(n).
 */

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> us;
        for (auto& num: arr) {
            if (us.find(num << 1) != us.end()) return true;
            if (!(num & 1) && us.find(num >> 1) != us.end()) return true;
            us.insert(num);
        }
        return false;
    }
};
