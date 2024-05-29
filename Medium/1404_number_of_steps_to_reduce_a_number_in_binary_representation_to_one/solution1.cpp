/**
 * Title:  Number of Steps To Reduce A Number In Binary Representation To One (Leetcode Medium 1404)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, May, 2024
 */

class Solution {
private:
    int n;
public:
    int helper(string& s, int zeros) {
        // cout << s << " " << zeros << "\n";
        if (zeros == n - 1 && s[n - 1] == '1') return 0;
        if (s[n - 1] == '1') { // odd: add one
            zeros++;
            s[n - 1] = '0';
            int c = 1;
            int i = n - 2;
            while (c > 0 && i >= 0) {
                if (s[i] == '0') {
                    c--;
                    zeros--;
                    s[i] = '1';
                } else {
                    zeros++;
                    s[i] = '0';
                }
                i--;
            }
            if (c > 0 && i < 0) {
                s = "1" + s;
                n++;
            }
        } else { // even: divide 2
            zeros--;
            s.pop_back();
            n--;
        }
        return 1 + helper(s, zeros);
    }
    int numSteps(string s) {
        n = s.length();
        int zeros = 0;
        for (auto& c: s) {
            if (c == '0') zeros++;
        }
        return helper(s, zeros);
    }
};
