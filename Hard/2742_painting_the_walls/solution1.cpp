/**
 * Title:  Painting The Walls (Leetcode Hard 2742)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, October, 2023
 * Method: Top-down DP. State: dp(i, w) = the minimum cost to paint `w` walls when considering index `i` and beyond
 * Result: Time complexity O(n^2). Space complexity O(n^2).
 */

class Solution {
private:
    int big = 1e9;
    int n;
public:
    int dp(int i, int w, vector<int>& cost, vector<int>& time, vector<vector<int>>& memo) {
        // i: the wall index we are going to paint
        // w: the remaining walls we need to paint
        if (w <= 0) return 0;
        if (i == n) return big;
        if (memo[i][w] != -1)
            return memo[i][w];
        int paint = cost[i] + dp(i + 1, w - 1 - time[i], cost, time, memo);
        int dontPaint = dp(i + 1, w, cost, time, memo);
        return memo[i][w] = min(paint, dontPaint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return dp(0, n, cost, time, memo);
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
