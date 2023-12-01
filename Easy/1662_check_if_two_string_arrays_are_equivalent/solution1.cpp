/**
 * Title:  Check If Two Strings Arrays are Equivalent (Leetcode Easy 1662)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   1, December, 2023
 * Result: Time complexity: O(n), Space complexity: O(1).
 */

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, i = 0;
        int w2 = 0, j = 0;
        int n = word1.size(), m = word2.size();
        while (w1 < n && w2 < m) {
            // cout << w1 << " " << i << ", " << w2 << " " << j << "\n";
            if (word1[w1][i] != word2[w2][j]) {
                return false;
            } else {
                i++;
                j++;
            }

            if (i == word1[w1].length()) {
                i = 0;
                w1++;
            }
            if (j == word2[w2].length()) {
                j = 0;
                w2++;
            }
        }
        if (w1 == n && w2 == m)
            return true;
        return false;
    }
};
