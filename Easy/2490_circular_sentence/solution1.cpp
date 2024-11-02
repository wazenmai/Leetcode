/**
 * Title:  Circular Sentnece (Leetcode Easy 2490)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, November, 2024
 */

class Solution {
public:
    bool isCircularSentence(string& sentence) {
        int n = sentence.length();
        if (sentence[0] != sentence[n - 1]) return false;
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) return false;
            }
        }
        return true;
    }
};
