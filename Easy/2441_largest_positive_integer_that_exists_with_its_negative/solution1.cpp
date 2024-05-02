/**
 * Title:  Largest Positive Integer That Exists With Its Negative (Leetcode Easy 2441)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, May, 2024
 */

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int ans = -1;
        for (auto& num: nums) {
            if (s.find(-num) != s.end()) {
                if (num < 0) {
                    ans = max(ans, -num);
                } else {
                    ans = max(ans, num);
                }
                s.erase(-num);
            } else {
                s.insert(num);
            }
        }
        return ans;
    }
};
