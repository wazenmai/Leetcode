/**
 * Title:  Different Ways to Add Parentheses (Leetcode Medium 241)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, September, 2024
 * Method: Iterate through string, when we meet an operator, we can break the expression into two parts, and calculate the result of the two parts. We can use recursion to solve this problem.
 *         We can use a map to store the result of the expression, so that we can avoid duplicate calculation.
 * Result: Time complexity is O(n * 2^n), space complexity is O(2^n), while n is the length of the expression. The space complexity of map is O(m^2), while m is the number of numbers in the expression.
 */

class Solution {
private:
    unordered_map<string, vector<int>> m;
    int compute(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return 0;
    }
    void print(vector<int>& v) {
        for (int& e: v) {
            cout << e << " ";
        }
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();
        if (n == 0) return {};
        if (n <= 2) return {stoi(expression)};
        if (m.find(expression) != m.end()) {
            return m[expression];
        }
        vector<int> ans;
        // cout << expression << "\n";
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c >= '0' && c <= '9') continue;
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (int l: left) {
                for (int r: right) {
                    ans.emplace_back(compute(l, r, c));
                }
            }
            cout << expression << ", " << i << "\n";
            cout << c << ", left: ";
            print(left);
            cout << ", right: ";
            print(right);
            cout << ", ans: ";
            print(ans);
            cout << "\n";
        }
        return m[expression] = ans;
    }
};

/*
Time complexity: O(n x 2^n)
- iterate through string: n
- combining results takes O(l x r)
- O(2^n): number of ways to combine results from sub-expressions
Space complexity: O(2^n)

Optimized Solution, m is number of numbers
Time complexity: O(n * 2^n)
Space complexity of map: O(m^2) = O((m- 1)(m-2) / 2) = 1 + 2 + ... + m - 1
Space complexity of recursion: O(2^n)
*/
