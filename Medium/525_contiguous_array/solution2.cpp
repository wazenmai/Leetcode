/**
 * Title:  Contiguous Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   4, Feb, 2022
 * Method: Save memory -> from index vector to smallest index (int)
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        int temp_sum = 0;
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                --temp_sum;
            else
                ++temp_sum;
            // cout << i << ": " << temp_sum << "\n";
            if (temp_sum == 0)
                ans = max(ans, i + 1);
            if (hash_table[temp_sum] > 0) {
                // cout << "find " << temp_sum << ": " << hash_table[temp_sum] << "\n";
                ans = max(ans, i - hash_table[temp_sum] + 1);
            } else {
                hash_table[temp_sum] = i + 1;
            }
        }
        return ans;
    }
};
