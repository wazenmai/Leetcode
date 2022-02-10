/**
 * Title:  K-diff Pairs in an Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   9, Feb, 2022
 * Method: O(N^2) time, O(N) memory
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n < 2)
            return 0;
        unordered_map<long long, int> hash_table;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] - nums[j] == k) {
                    long long int temp = (long long)nums[i] * 10000000 + (long long)nums[j];
                    if (!hash_table[temp]) {
                        ans += 1;
                        hash_table[temp] += 1;
                    }
                } else if (nums[j] - nums[i] == k) {
                    long long int temp = (long long)nums[j] * 10000000 + (long long)nums[i];
                    if (!hash_table[temp]) {
                        ans += 1;
                        hash_table[temp] += 1;
                    }
                }
            }
        }
        return ans;
    }
};
