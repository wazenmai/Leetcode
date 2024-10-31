/**
 * Title:  Minimum Total Distance Traveled (Leetcode Hard 2463)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, October, 2024
 * Method: First we sort the robots and factories. Then we separate factories into one limit for each. If # of factories = # of robots, the answer is trivial.
 *         Otherwise, use DP. dp[i][j] = minimum distance for first i robots go to first j factories. Bounding condition: dp[0][j] = 0 since no robots  = 0 distance.
 *         For transition, when adding new factory, there are 2 cases. (1) robot i go to original j factories. (2) robot (i - 1) go to original j factories, robot i go to factory j.
 * Result: Time complexity O(nm). Space complexity O(nm). m = # of factories.
 */

class Solution {
public:
    void print(vector<int>& v) {
        for (auto& e: v) {
            cout << e << ",";
        }
        cout << "\n";
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factories; // factories position (one limit for each)
        for (auto& fac: factory) {
            for (int i = 0; i < fac[1]; i++) {
                factories.emplace_back(fac[0]);
            }
        }
        int n = robot.size(), m = factories.size();
        if (factories.size() == robot.size()) { // robot i go to factory i
            long long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += abs(robot[i] - factories[i]);
            }
            return ans;
        }
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX)); // minimum distance for first i robots go to first j factories
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0; // no robot, distance = 0
        }
        for (int i = 0; i < n; i++) { // robot
            for (int j = i; j < m; j++) { // factory
                // case 1: robot i go to original j factories
                // case 2: robot (i - 1) go to original j factories, robot i go to factor j
                dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j] + abs((long long)robot[i] - factories[j]));
            }
        }
        return dp[n][m];
    }
};

// first condition, factory.limit = robot.size -> trivial, when meet robot or factory, just repair it
// second condition, factory.limit > robot.size
// | 100, 50 |2, 2|50, 75|
//   100,25|
// dp[i][j] = minimum total distance to repair robot 0 ~ i with factory 0 ~ j
// dp[0][0] = inf. 
// dp[i][j] = min(dp[i][j], dp[i][j - 1], dp[i - 1][j])
