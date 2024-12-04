/**
 * Title:  Adding Spaces to a String (Leetcode Medium 2109)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, December, 2024
 */

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        size_t n = s.length();
        size_t m = spaces.size();
        size_t j = 0;
        for (size_t i = 0; i < n; i++) {
            if (j < m && i == spaces[j]) {
                ans += ' ';
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};
