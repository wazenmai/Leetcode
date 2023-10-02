/**
 * Title:  Remove Color Pieces If Both Neighbors Are The Same Color (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, October, 2023
 */

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int a = 0;
        int b = 0;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] == 'A' && colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
                a++;
            else if (colors[i] == 'B' && colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
                b++;
        }
        if (a == 0 || a <= b)
            return false;
        return true;
    }
};
