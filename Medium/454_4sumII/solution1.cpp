/**
 * Title:  4Sum II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   3, Feb, 2022
 * Result: TLE
 */

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        for (auto& n1 : nums1) {
            int temp_sum = n1;
            for (auto& n2 : nums2) {
                temp_sum += n2;
                for (auto& n3 : nums3) {
                    temp_sum += n3;
                    for (auto& n4 : nums4) {
                        temp_sum += n4;
                        if (temp_sum == 0)
                            ans += 1;
                        temp_sum -= n4;
                    }
                    temp_sum -= n3;
                }
                temp_sum -= n2;
            }
            temp_sum -= n1;
        }
        return ans;
    }
};
