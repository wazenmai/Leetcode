/**
 * Title:  Delete Columns to Make Sorted (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, Janurary, 2023
 */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            char c = 'a';
            for (int i = 0; i < n; i++) {
                if (c <= strs[i][j]) {
                    c = strs[i][j];
                } else {
                    ans += 1;
                    break;
                }
            }
        }
        return ans;
    }
};
