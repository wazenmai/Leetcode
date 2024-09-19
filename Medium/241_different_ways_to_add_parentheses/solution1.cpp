/**
 * Title:  Different Ways to Add Parentheses (Leetcode Medium 241)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, September, 2024
 * Method: Number of possible answers grow with Catalan number. We can break 3 to (2, 1) and (1, 2). 4 to (1, 3), (2, 2), (3, 1). While 3 can break into 2 possibilities, so if we have 4 number, we have 5 possibilities. We can use recursion to solve this problem.
 *         My initial thought is add parenthese to original expression, and use `compute` to calculate the result. But it's hard to add parenthese to the expression.
 * Result: Failed.
 */

struct Node {
    int num;
    char op;
    Node(int _num, char _op) {
        num = _num;
        op = _op;
    }
};

class Solution {
private:
    vector<int> ans;
    int compute(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return 0;
    }
    bool isop(char c) {
        if (c == '+' || c == '-' || c == '*' || c == '(') return true;
        return false;
    }
public:
    void compute(string& expression) {
        int res = 0;
        stack<Node> st;
        int num = 0;
        bool is_num = false;
        for (auto& c: expression) {
            if (c == ')') { // take out till (
                if (is_num) {
                    st.push(Node(num, 0));
                    is_num = false;
                    num = 0;
                }
                int left = 0, right = 0;
                char op;
                bool right_end = false;
                while (!st.empty()) {
                    auto cur = st.top();
                    st.pop();
                    if (cur.op == '(') {
                        break;
                    } else if (isop(cur.op)) {
                        op = cur;
                        right_end = true;
                    } else { // num
                        if (right_end) {
                            left = cur.num;
                        } else {
                            right = cur.num;
                        }
                    }
                }
                int temp = compute(left, right, op);
                st.push(Node(temp, 0));
            } else if (isop(c)) {
                if (is_num) {
                    st.push(Node(num, 0));
                    is_num = false;
                    num = 0;
                }
                st.push(Node(0, c));
            } else {
                num = num * 10 + c - '0';
                is_num = true;
            }
        }
        ans.emplace_back(st.top());
    }
    vector<string> recur(string expression, int nums) {
        if (nums == 2) return vector<string>{"(" + expression + ")"};
        if (nums == 3) {
            string s1 = "(";
            int n = expression.length();
            int i = 0;
            while (i < n && !isop(expression[i])) i++;
            s1 += expression.substr(0, i + 1);
            s1 += recur(expression.substr(i + 1), 2)[0];
            string s2 = ")";
            i = n - 1;
            while (i > 0 && !isop(expression[i])) i--;
            s2 = expression.substr(i) + s2;
            s2 = recur(expression.substr(0, i), 2)[0] + s2;
            return vector<string>{s1, s2};
        }
        vector<string> res;
        for (int i = 1; i <= nums - 1; i++) {
            
        }
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = 1;
        for (auto& c: expression) {
            if (isop(c)) n++;
        }
        if (n == 2) {
            int num1 = 0;
            int num2 = 0;
            char op = 0;
            for (auto& c: expression) {
                if (isop(c)) {
                    op = c;
                } else if (op == 0) {
                    num1 = num1 * 10 + c - '0';
                } else {
                    num2 = num2 * 10 + c - '0';
                }
            }
            return compute(num1, num2, op);
        }
        for (int i = 1; i <= n - 1; i++) {
            // (i, nums - 1)

        }
        return ans;
    }
};

// 2*3-4*5+1 9
// 
