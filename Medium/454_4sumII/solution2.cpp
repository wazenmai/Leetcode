/**
 * Title:  4Sum II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   3, Feb, 2022
 * Method: O(N^2) time
 */

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int, int> hash_table;
        for (auto& n1 : nums1) {
            for (auto& n2 : nums2) {
                ++hash_table[n1 + n2];
            }
        }
        
        for (auto& n3 : nums3) {
            for (auto& n4 : nums4) {
                ans += hash_table[- (n3 + n4)];
            }
        }
        return ans;
    }
};
