/**
 * Title:  Sequential Digits (Leetcode Medium 1291)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, Jan, 2022
 * Result: Runtime 0ms, Memory Usage 6.1 MB
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 2; i <= 9; i++) {
            char st = '1';
            while (st <= '9' - i + 1) {
                string temp = "";
                int comp = 0;
                for (int j = 0; j <= i - 1; j++) {
                    temp += (st + j);
                    comp = comp * 10 + (st + j - '0');
                }
                ++st;
                if (comp >= low && comp <= high)
                    ans.emplace_back(comp);
            }
        }
        return ans;
    }
};
