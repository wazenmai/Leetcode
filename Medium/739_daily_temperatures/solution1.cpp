/**
 * Title:  Daily Temperatures (Leetcode Medium 739)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, Janurary, 2024
 * Method: Use stack to store the index and temperature, the lowest temperature is at the top of the stack.
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
            while (!s.empty()) {
                auto cur = s.top();
                if (temperatures[i] > cur.second) {
                    ans[cur.first] = i - cur.first;
                    s.pop();
                } else {
                    break;
                }
            }
            if (i == n - 1) break;
            if (s.empty()) {
                s.push(make_pair(i, temperatures[i]));
            } else {
                stack<pair<int, int>> temp;
                while(!s.empty() && s.top().second < temperatures[i]) {
                    temp.push(s.top());
                    s.pop();
                }
                s.push(make_pair(i, temperatures[i]));
                while (!temp.empty()) {
                    s.push(temp.top());
                    temp.pop();
                }
            }
        }
        return ans;
    }
};
