/**
 * Title:  Fraction Addition and Subtraction (Leetcode Medium 592)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, August, 2024
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
    string fractionAddition(string expression) {
        queue<pair<int, int>> nums;
        queue<char> op;
        string num = "";
        int molecular = -1;
        int denominator = 0;
        for (auto& c: expression) {
            if (c == '/') {
                molecular = stoi(num);
                num = "";
            } else if (c == '+') {
                op.push('+');
                denominator = stoi(num);
                nums.push(make_pair(molecular, denominator));
                molecular = -1;
                num = "";
            } else if (c == '-') {
                op.push('-');
                if (molecular != -1) {
                    denominator = stoi(num);
                    nums.push(make_pair(molecular, denominator));
                    molecular = -1;
                    num = "";
                }
            } else {
                num += c;
            }
        }
        denominator = stoi(num);
        nums.push(make_pair(molecular, denominator));
        molecular = nums.front().first;
        denominator = nums.front().second;
        if (nums.size() == op.size()) {
            molecular = 0 - molecular;
            op.pop();
        }
        nums.pop();
        while (!nums.empty()) {
            auto v = nums.front();
            int new_d = lcm(denominator, v.second);
            // cout << molecular << "/" << denominator << op.front() << v.first << "/" << v.second << "\n";
            // cout << "lcm: " << new_d << "\n";
            int v_m = (op.front() == '+') ? v.first * (new_d / v.second) : 0 - v.first * (new_d / v.second);
            molecular = molecular * (new_d / denominator) + v_m;
            denominator = new_d;
            nums.pop();
            op.pop();
        }
        string ans = "";
        if (molecular < 0) {
            ans += "-";
            molecular = 0 - molecular;
        }
        int common = gcd(molecular, denominator);
        molecular /= common;
        denominator /= common;
        ans += to_string(molecular) + "/" + to_string(denominator);
        return ans;
    }
};
