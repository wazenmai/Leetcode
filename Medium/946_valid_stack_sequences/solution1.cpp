/**
 * Title:  Valid Stack Sequences (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, Mar, 2022
 */

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = (int)pushed.size();
        int push_id = 1;
        int pop_id = 0;
        st.push(pushed[0]);
        while (pop_id < n) {
            if (!st.empty() && popped[pop_id] == st.top()) {
                pop_id++;
                st.pop();
            } else if (push_id < n) {
                st.push(pushed[push_id]);
                push_id++;
            } else {
                return false;
            }
        }
        return (st.empty()) ? true : false;
    }
};
