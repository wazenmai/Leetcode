/**
 * Title:  K-diff Pairs in an Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   9, Feb, 2022
 * Method: O(N) time, O(N) memory
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n < 2)
            return 0;
        unordered_map<int, int> hash_num;
        unordered_map<long long, int> hash_table;
        int ans = 0;
        
        for (auto& n : nums) {
            hash_num[n] += 1;
        }
        for (auto& n : nums) {
            if (k == 0) {
                if (hash_num[n] > 1 && !hash_table[(long long)(n) * 10000000 + n]) {
                    hash_table[(long long)(n) * 10000000 + n] = 1;
                    ans += 1;
                }
            } else {
                if (hash_num[n + k] && !hash_table[(long long)(n + k) * 10000000 + n]) {
                    hash_table[(long long)(n + k) * 10000000 + n] = 1;
                    ans += 1;
                }
                if (hash_num[n - k] && !hash_table[(long long)(n) * 10000000 + (n - k)]) {
                    hash_table[(long long)(n) * 10000000 + n - k] = 1;
                    ans += 1; 
                }
            }
        }
        return ans;
    }
};
