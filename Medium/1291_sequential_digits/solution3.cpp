/**
 * Title:  Sequential Digits (Leetcode Medium 1291)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, February, 2024
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> nums;
        vector<int> ans;
        for (int i = 0; i < 9; i++) {
            string x = "";
            for (int j = i; j < 9; j++) {
                x += s[j];
                int num = stoi(x);
                if (low <= num && num <= high) {
                    ans.emplace_back(num);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
