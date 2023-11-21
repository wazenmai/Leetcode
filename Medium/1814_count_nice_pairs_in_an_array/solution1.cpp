/**
 * Title:  Count Nice Pairs in an Array (Leetcode Medium 1814)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, November, 2023
 * Method: Use unordered_map to store the difference between nums[i] and rev(nums[i]), sum of C(n, 2) = n * (n - 1) / 2 is the ans.
 * Result: Time complexity O(n), space complexity O(n)
 */

class Solution {
public:
    int mod = 1e9 + 7;
    int rev(int num) {
        int res = 0;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num: nums) {
            m[num - rev(num)]++;
        }
        long long ans = 0;
        for (auto it = m.begin();it != m.end(); it++) {
            if (it->second > 1) {
                ans += ((long long)it->second * (it->second - 1)) / 2;
                ans %= mod;
            }
        }
        return (int)ans;
    }
};
// nums[i] + rev(nums[j]) = nums[j] + rev(nums[i])
// nums[i] - rev(nums[i]) = nums[j] - rev[nums[j]]
// 4 (1, 2) (1, 3) (1, 4) (2, 3) (3, 4)
