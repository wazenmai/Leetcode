/**
 * Title:  Make Two Arrays Equal by Reversing Subarrays (Leetcode Easy 1460)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, August, 2024
 * Result: Time complexity O(n^2), Space complexity O(1).
 */

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        for (auto& num: target) {
            int cnt = count(target.begin(), target.end(), num);
            int cnt2 = count(arr.begin(), arr.end(), num);
            if (cnt != cnt2) return false;
        }
        return true;
    }
};
