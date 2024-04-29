/**
 * Title:  Minimum Number of Operations to Make Array XOR Equal to K (Leetcode Medium 2997)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, April, 2024
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s = 0;
        for (auto& num: nums) {
            s ^= num;
        }
        if (s == k) return 0;
        int ans = 0;
        while (s != k) {
            int s_temp = s % 2;
            int k_temp = k % 2;
            // cout << s << " " << k << ", " << s_temp << "," << k_temp << "\n";
            if (s_temp != k_temp) ans++;
            s /= 2;
            k /= 2;
        }
        return ans;
    }
};
