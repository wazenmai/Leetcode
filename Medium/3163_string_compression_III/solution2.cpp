/**
 * Title:  String Compression III (Leetcode Medium 3163)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, November, 2024
 * Method: Decrease the number of if-else statements compared to solution1.cpp. -> Speed up.
 * Result: Time complexity O(n). Space complexity O(1). Time: 17ms -> 7ms.
 */

class Solution {
public:
    string compressedString(string& word) {
        string comp = "";
        int n = word.length();
        char temp = word[0];
        int repeat = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] == temp) {
                if (repeat < 9) {
                    repeat++;
                    continue;
                }
                comp += '9';
                comp += temp;
                temp = word[i];
                repeat = 1;
            } else {
                comp += (repeat + '0');
                comp += temp;
                temp = word[i];
                repeat = 1;
            }
        }
        comp += (repeat + '0');
        comp += temp;
        return comp;
    }
};
