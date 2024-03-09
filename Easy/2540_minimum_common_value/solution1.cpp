/**
 * Title:  Minimum Common Value (Leetcode Easy 2540)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, March, 2024
 * Method: Use unordered_map to store the frequency of each number in nums1. Then traverse nums2 and find the number with the highest frequency in nums1 that also appears in nums2. Return the number with the highest frequency.
 * Result: Time complexity O(n + m). Space complexity O(n). // unordered_map has average time complexity O(1).
 */

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int max_num = -1;
        int max_cnt = 0;
        unordered_map<int, int> m;
        for (auto& num: nums1) {
            m[num]++;
        }
        int temp = -1;
        int cnt = 0;
        for (auto& num: nums2) {
            // cout << num << ", " << temp << ", " << cnt << "\n";
            if (num != temp) {
                if (cnt > 0) {
                    int cnt1 = m[temp];
                    // cout << "check nums1: " << cnt1 << ", nums2:" << cnt << "\n";
                    if (cnt1 > 0 && min(cnt, cnt1) > max_cnt) {
                        max_num = temp;
                        max_cnt = min(cnt, cnt1);
                    }
                }
                temp = num;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        int cnt1 = m[temp];
        if (cnt1 > 0 && min(cnt, cnt1) > max_cnt) {
            max_num = temp;
            max_cnt = min(cnt, cnt1);
        }
        return max_num;
    }
};
