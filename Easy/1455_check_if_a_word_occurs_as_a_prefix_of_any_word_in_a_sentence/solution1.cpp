/**
 * Title:  Check If a Word Occurs As a Prefix of Any Word in a Sentence (Leetcode Easy 1455)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, December, 2024
 */

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length();
        int m = searchWord.length();
        bool compare = true;
        int j = 0;
        int word = 1;
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                compare = true;
                j = 0;
                word++;
            } else if (compare && sentence[i] == searchWord[j]) {
                j++;
            } else {
                compare = false;
            }
            if (j == m) return (sentence[i] == ' ') ? word - 1 : word;
        }
        return -1;
    }
};