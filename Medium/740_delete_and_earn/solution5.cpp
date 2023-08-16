/**
 * Title:    Delete And Earn (Leetcode Medium)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     16, August, 2023
 * Method:   Memory optimization for Top-Down DP. Only use dp[2] and max_num - min_num + 1 for count.
 */

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_num = 0;
        int min_num = 10001;
        for (int num: nums) {
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        vector<int> count(max_num - min_num + 1, 0);
        for (int num: nums)
            count[num - min_num]++;
        if (max_num == min_num)
            return count[0] * min_num;
        int dp[2];
        dp[0] = count[0] * min_num;
        dp[1] = max(dp[0], count[1] * (min_num + 1));
        for (int i = min_num + 2; i <= max_num; i++) {
            int temp = max(count[i - min_num] * i + dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = temp;
        }
        return dp[1];
    }
};
