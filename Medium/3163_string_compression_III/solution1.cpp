/**
 * Title:  String Compression III (Leetcode Medium 3163)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, November, 2024
 */

class Solution {
public:
    string compressedString(string& word) {
        string comp = "";
        int n = word.length();
        char temp = word[0];
        int repeat = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] != temp) {
                comp += (repeat + '0');
                comp += temp;
                temp = word[i];
                repeat = 1;
            } else if (repeat == 9) {
                comp += '9';
                comp += temp;
                temp = word[i];
                repeat = 1;
            } else {
                repeat++;
            }
        }
        comp += (repeat + '0');
        comp += temp;
        return comp;
    }
};
