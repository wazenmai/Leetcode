/**
 * Title:  Asteroid Collision (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, July, 2023
 * Method: Using stack. Time complexity O(n)
 */

class Solution {
public:
    void printVec(vector<int>& v) {
        for (int e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = (int)asteroids.size();
        stack<int> leave;
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                leave.push(asteroids[i]);
            } else { // to left
                while(!leave.empty() && -asteroids[i] > leave.top()) {
                    if (leave.top() > 0)
                        leave.pop();
                    else
                        break;
                }
                if (!leave.empty() && -asteroids[i] == leave.top()) {
                    leave.pop();
                } else if (!leave.empty() && leave.top() > -asteroids[i] && leave.top() > 0) {
                    continue;
                } else {
                    leave.push(asteroids[i]);
                }
            }
        }
        while (!leave.empty()) {
            ans.emplace_back(leave.top());
            leave.pop();
        }
        if (ans.size() <= 1)
            return ans;
        vector<int> new_ans;
        for (int i = (int)ans.size() - 1; i >= 0; i--) {
            new_ans.emplace_back(ans[i]);
        }
        return new_ans;
    }
};
