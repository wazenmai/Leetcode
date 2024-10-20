/**
 * Title:  Parsing A Boolean Expression (Leetcode Hard 1106)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, October, 2024
 * Result: Time complexity O(n). Space complexity O(n).
 */

class Solution {
public:
    bool calc(bool a, char b, char c) {
        if (c == '&') {
            return a & transform(b);
        } else if (c == '|') {
            return a | transform(b);
        }
        return (a) ? false : true;
    }
    bool transform(char c) {
        return (c == 't') ? true : false;
    }
    char transform_bool(bool a) {
        return (a) ? 't' : 'f';
    }
    bool parseBoolExpr(string& expression) {
        stack<char> st, op;
        for (auto& c: expression) {
            if (c == ',') continue;
            if (c == '&' || c == '|' || c == '!') {
                op.push(c);
            } else if (c == ')') {
                bool ans = transform(st.top());
                st.pop();
                while (!st.empty() && st.top() != '(') {
                    ans = calc(ans, st.top(), op.top());
                    st.pop();
                }
                st.pop(); // pop '('
                if (op.top() == '!') {
                    ans = calc(ans, 0, op.top());
                }
                op.pop();
                st.push(transform_bool(ans));
            } else {
                st.push(c);
            }
        }
        return transform(st.top());
    }
};
