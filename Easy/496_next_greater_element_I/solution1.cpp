/**
 * Title:  Next Greater Element (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Mar, 2021
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int num1_size = nums1.size();
        int num2_size = nums2.size();
        int ngn = -1;
        bool flag = false;
        for (int i = 0; i < num1_size; i++) {
            flag = false;
            ngn = -1;
            for (int j = 0; j < num2_size; j++) {
                if (flag) {
                    if (nums2[j] > nums1[i]) {
                        ngn = nums2[j];
                        break;
                    }
                }
                if (nums2[j] == nums1[i]) {
                    flag = true;
                }
            }
            ans.emplace_back(ngn);
        }
        return ans;
    }
};