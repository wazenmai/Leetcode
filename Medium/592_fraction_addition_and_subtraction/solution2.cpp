/**
 * Title:  Fraction Addition and Subtraction (Leetcode Medium 592)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, August, 2024
 * Method: Tidy code. Calculate while reading the expression.
 */

class Solution {
public:
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
    int lcm(int x, int y) {
        return x * y / gcd(x, y);
    }
    pair<int, int> calculate(int cur_up, int cur_down, int next_up, int next_down, char op) {
        int new_down = lcm(cur_down, next_down);
        next_up = next_up * (new_down / next_down);
        if (op == '-') {
            cur_up = cur_up * (new_down / cur_down) - next_up;
        } else {
            cur_up = cur_up * (new_down / cur_down) + next_up;
        }
        return make_pair(cur_up, new_down);
    }
    string fractionAddition(string expression) {
        string num = "";
        pair<int, int> cur = make_pair(0, 1);
        int molecular = -1;
        char op = '+';
        for (auto& c: expression) {
            if (c == '/') {
                molecular = stoi(num);
                num = "";
            } else if (c == '+') {
                int denominator = stoi(num);
                cur = calculate(cur.first, cur.second, molecular, denominator, op);
                op = '+';
                num = "";
            } else if (c == '-') {
                if (molecular != -1) {
                    int denominator = stoi(num);
                    cur = calculate(cur.first, cur.second, molecular, denominator, op);
                }
                op = '-';
                num = "";
            } else {
                num += c;
            }
        }
        int denominator = stoi(num);
        cur = calculate(cur.first, cur.second, molecular, denominator, op);
        string ans = "";
        if (cur.first < 0) {
            ans += "-";
            cur.first = -cur.first;
        }
        int common = gcd(cur.first, cur.second);
        cur.first /= common;
        cur.second /= common;
        ans += to_string(cur.first) + "/" + to_string(cur.second);
        return ans;
    }
};
