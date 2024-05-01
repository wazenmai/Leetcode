/**
 * Title:  Reverse Prefix of Word (Leetcode Easy 2000)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, May, 2024
 */

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = -1;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if (word[i] == ch) {
                j = i;
                break;
            }
        }
        if (j == -1) return word;
        for (int i = 0; i < (j + 1) / 2; i++) {
            char temp = word[i];
            word[i] = word[j - i];
            word[j - i] = temp;
        }
        return word;
    }
};
