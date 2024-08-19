/**
 * Title:  2 Keys Keyboard (Leetcode Medium 650)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, August, 2024
 */

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int word = 1;
        int copy = 0;
        while (word < n) {
            if (copy == 0) { // copy
                copy = word;
            } else if (copy == word) { // paste
                word += copy;
            } else if ((n - word) % word == 0) {
                copy = word;
            } else {
                word += copy;
            }
            ans++;
        }
        return ans;
    }
};

// n=6
// A, word=1, copy=0 -> C
// A, word=1, copy=1 -> P
// AA, word=2, copy=1 -> C
// AA, word=2, copy=2 -> P
// AAAA, word=4, copy=2 -> P
// AAAAAA
