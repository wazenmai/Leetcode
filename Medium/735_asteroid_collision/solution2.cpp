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
        stack<int> st;
        for (int a: asteroids) {
            int flag = 1;
            while (!st.empty() && (st.top() > 0 && a < 0)) { // now a is to left
                if (abs(st.top()) < abs(a)) {
                    st.pop();
                    continue;
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();
                }
                flag = 0;
                break;
            }
            if (flag)
                st.push(a);
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
