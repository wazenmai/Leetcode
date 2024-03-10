/**
 * Title:  Intersection of Two Arrays (Leetcode Easy 349)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, March, 2024
 * Method: Use unordered_map to store the frequency of each number in nums1. Then traverse nums2 and find the number that also appears in nums1. Return the numbers that appear in both nums1 and nums2.
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (auto& num: nums1) {
            m[num]++;
        }
        unordered_set<int> s;
        for (auto& num: nums2) {
            if (m[num] != 0) s.insert(num);
        }
        vector<int> ans;
        for (auto it = s.begin(); it != s.end(); it++) {
            ans.emplace_back(*it);
        }
        return ans;
    }
};
