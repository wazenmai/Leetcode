/**
 * Title:  Intersection of Two Arrays II (Leetcode Easy 350)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, July, 2024
 * Method: First sorted the two arrays, then use two pointers to find the repetitive elements.
 * Result: Time complexity is O(nlogn + mlogm), space complexity is O(1).
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        vector<int> ans;
        while (i < n && j < m) {
            if (nums1[i] > nums2[j])
                j++;
            else if (nums2[j] > nums1[i])
                i++;
            else if (nums1[i] == nums2[j]) {
                ans.emplace_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
