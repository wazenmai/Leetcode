/**
 * Title:    Delete And Earn (Leetcode Medium)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     16, August, 2023
 * Method:   Top-Down DP.
 */

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> count(n, 0);
        int max_num = 0;
        int min_num = n;
        for (int num: nums) {
            count[num]++;
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        vector<int> dp(n, -1);
        dp[min_num] = count[min_num] * min_num;
        if (min_num + 1 < n)
            dp[min_num + 1] = max(count[min_num] * min_num, count[min_num + 1] * (min_num + 1));
        for (int i = min_num + 2; i <= max_num; i++) {
            dp[i] = max(count[i] * i + dp[i - 2], dp[i - 1]);
        }
        return dp[max_num];
    }
};
