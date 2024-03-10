/**
 * Title:  Intersection of Two Arrays (Leetcode Easy 349)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, March, 2024
 * Method: Only use one unordred_map and when meet intersection erase that number in unordered_map.
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (auto& num: nums1) {
            m[num]++;
        }
        vector<int> ans;
        for (auto& num: nums2) {
            if (m[num] != 0) {
                ans.emplace_back(num);
                m.erase(num);
            }
        }
        return ans;
    }
};
