/**
 * Title:  Delete and Earn (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, Mar, 2022
 * Method: Retidy the code
 */

class Solution {
public:
    int dfs(vector<int>& dp, vector<int>& v, int pick, int end) {
        if (pick > end)
            return 0;
        if (dp[pick])
            return dp[pick];
        return (dp[pick] = v[pick] * pick + max(dfs(dp, v, pick + 2, end), dfs(dp, v, pick + 3, end)));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v(10002, 0);
        int ans = 0;
        int maximum = 0;
        for (auto& x : nums) {
            ++v[x];
            maximum = max(maximum, x);
        }
        maximum = min(maximum + 1, 10001);
        vector<int> dp(maximum, 0);
        
        int start = 0;
        for (int i = 1; i <= maximum; i++) {
            if (v[i]) {
                if (start == 0)
                    start = i;
            } else if (start == 0) {
                continue;
            } else {
                if (start == i - 1)
                    ans += v[start] * start;
                else
                    ans += max(dfs(dp, v, start, i - 1), dfs(dp, v, start + 1, i - 1));
                start = 0;
            }
        }
        return ans;
    }
};
