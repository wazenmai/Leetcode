/**
 * Title:  Largest Rectangle in Histogram (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, Jan, 2022
 * Method: Use stack and only pop out when top > current height, it means that top.height's right boundary is at current index - 1.
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;
        int n = (int)heights.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int st = i;
            while (!stk.empty() && stk.top().second >= heights[i]) {
                ans = max(ans, stk.top().second * (i - stk.top().first));
                st = stk.top().first;
                stk.pop();
            }
            stk.push(make_pair(st, heights[i]));
        }
        while (!stk.empty()) {
            ans = max(ans, stk.top().second * (n - stk.top().first));
            stk.pop();
        }
        return ans;
    }
};
