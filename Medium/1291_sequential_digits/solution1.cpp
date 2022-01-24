/**
 * Title:  Sequential Digits (Leetcode Medium 1291)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, Jan, 2022
 */

class Solution {
private:
    int myAtoi(string& s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            ans = ans * 10 + (s[i] - '0');
        }
        return ans;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        vector<string> seq;
        for (int i = 2; i <= 9; i++) {
            char st = '1';
            while (st <= '9' - i + 1) {
                string temp = "";
                for (int j = 0; j <= i - 1; j++) {
                    temp += (st + j);
                }
                seq.emplace_back(temp);
                ++st;
            }
        }
        for (auto& sd : seq) {
            int comp = myAtoi(sd);
            if (comp < low)
                continue;
            if (comp > high)
                break;
            ans.emplace_back(comp);
        }
        return ans;
    }
};
