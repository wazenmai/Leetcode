/**
 * Title:  Painting The Walls (Leetcode Hard 2742)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, October, 2023
 * Method: Bottom-up DP with memory optimization.
 * Result: Time complexity O(n^2). Space complexity O(n).
 */

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n+1, 1e9);
        vector<int> pre(n+1, 1e9);
        pre[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                int paint = (j - 1 - time[i] <= 0) ? cost[i] : cost[i] + pre[j - 1 - time[i]];
                int dontPaint = pre[j];
                dp[j] = min(paint, dontPaint);
            }
            pre = dp;
        }
        return dp[n];
    }
};

// dp[i][0]: the cost of wall(0 - i) when ith wall is painted by paid painter
// dp[i][1]: the cost of wall(0 - i) when ith wall is painted by free painter

// The total amount of walls that can be painted by hiring the paid painter for any index i is equal to 1 + time[i], 1 for the wall that the paid painter paints and time[i] walls for the walls that the free painter can paint in that time. We're trying to find the lowest cost to get remaining walls less than or equal to 0.

// dp(i, remain): the minimum cost to paint `remain` walls when considering index `i` and beyond
//  if remain <= 0, we have painted all walls -> 0
//  if i == n, we have run out of walls to put paid painter -> inf
//  If we use paid painter at i-th wall, we spend cost[i] and paint 1 + time[i] walls,
//      the cost of this options is cost[i] + dp(i + 1, remain - 1 - time[i])
// If we use free painter, then the cost = dp(i + 1, remain)