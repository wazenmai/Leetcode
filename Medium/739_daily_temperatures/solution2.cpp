/**
 * Title:  Daily Temperatures (Leetcode Medium 739)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, Janurary, 2024
 * Method: Combine two stack loop.
 * Result: Time complexity O(n), Space complexity O(n)
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;
        s.push(make_pair(0, temperatures[0]));
        for (int i = 1; i < n; i++) {
            // fill in answer
            while (!s.empty() && s.top().second < temperatures[i]) {
                ans[s.top().first] = i - s.top().first;
                s.pop();
            }
            s.push(make_pair(i, temperatures[i]));
        }
        return ans;
    }
};
