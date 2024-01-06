/**
 * Title:  Maximum Profit in Job Scheduling (Leetcode Hard 1235)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, Janurary, 2024
 * Method: Since the time range is too big, use map to store the time and the max profit at that time. (dp)
         * dp[i] = max(dp[i], dp[start] + profit[j])
 * Result: Time complexity: O(nlogn), Space complexity: O(n)
 */

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs(n); // end, start, pro
        map<int, int> dp;
        int last = 1e9;
        for (int i = 0; i < n; i++) {
            jobs[i] = vector<int>{endTime[i], startTime[i], profit[i]};
            dp[startTime[i]] = 0;
            dp[endTime[i]] = 0;
            last = min(startTime[i], last);
        }
        sort(jobs.begin(), jobs.end());
        int ans = 0;
        int j = 0;
        for (auto it = dp.begin(); it != dp.end(); it++) {
            while (j < n && it->first == jobs[j][0]) {
                int start = jobs[j][1];
                int end = jobs[j][0];
                int profit = jobs[j][2];
                it->second = max(it->second, dp[start] + profit);
                j++;
            }
            it->second = max(it->second, dp[last]);
            ans = max(ans, it->second);
            last = it->first;
        }
        return ans;
    }
};

// dp[i]: max profit get at time i
// meet job j
// dp[i] = max(dp[i], dp[start] + profit[j])
// dp[0] = 0
