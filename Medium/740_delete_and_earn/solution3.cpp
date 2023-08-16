/**
 * Title:    Delete And Earn (Leetcode Medium)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     16, August, 2023
 * Method:   Recursive Dp. dp[i] = max(count[i] * i + dp[i + 2], dp[i + 1]). We can view this problem as a house robber problem. each house is the number in nums, and the money in each house is the count of the number * number. 
 * Analysis: Time complexity: O(n), n is nums size. Space complexity: O(m) (m is the max possible number in nums)
 */

class Solution {
private:
    int max_num;
public:
    int earn(vector<int>& count, vector<int>& dp, int i) {
        if (i > max_num)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = max(count[i] * i + earn(count, dp, i + 2), earn(count, dp, i + 1));
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        max_num = 0;
        int min_num = 100001;
        for (int num: nums) {
            count[num]++;
            max_num = max(max_num, num);
            min_num = min(min_num, num);
        }
        vector<int> dp(10001, -1);
        return earn(count, dp, min_num);
    }
};
