/**
 * Title:  Find First Palindromic String in the Array (Leetcode Easy 2108)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, February, 2024
 */

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& word: words) {
            int n = word.length();
            int id = 0;
            while (id <= n / 2) {
                if (word[id] == word[n - id - 1]) {
                    id++;
                } else {
                    break;
                }
            }
            if (id > n / 2)
                return word;
        }
        return "";
    }
};
// 0 1 2 3