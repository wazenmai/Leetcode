/**
 * Title:  Make Two Arrays Equal by Reversing Subarrays (Leetcode Easy 1460)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, August, 2024
 * Result: Time complexity O(n), Space complexity O(n).
 */

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt(1001, 0);
        for (auto& num: target) {
            cnt[num]++;
        }
        for (auto& num: arr) {
            cnt[num]--;
            if (cnt[num] < 0)
                return false;
        }
        return true;
    }
};
