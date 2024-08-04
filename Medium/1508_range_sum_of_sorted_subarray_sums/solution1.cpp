/**
 * Title:  Range Sum of Sorted Subarray Sums (Leetcode Medium 1508)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, August, 2024
 * Result: Time complexity O(n^2logn^2), Space complexity O(n^2).
 */

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        vector<int> sum;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = i; j < n; j++) {
                temp += nums[j];
                sum.emplace_back(temp);
            }
        }
        sort(sum.begin(), sum.end()); // n^2logn^2 = 10^6 * 2 * 10 = 10^7 
        // for (auto& num: sum) {
        //     cout << num << " ";
        // }
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sum[i]) % mod;
        }
        return ans;
    }
};
