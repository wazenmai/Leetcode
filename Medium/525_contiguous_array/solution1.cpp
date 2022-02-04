/**
 * Title:  Contiguous Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   4, Feb, 2022
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, vector<int>> hash_table;
        int temp_sum = 0;
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                --temp_sum;
            else
                ++temp_sum;
            if (temp_sum == 0)
                ans = max(ans, i + 1);
            if (!hash_table[temp_sum].empty())
                ans = max(ans, i - hash_table[temp_sum][0]);
            hash_table[temp_sum].emplace_back(i);   
        }
        return ans;
    }
};
