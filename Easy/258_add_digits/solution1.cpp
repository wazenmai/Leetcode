/**
 * Title:  Add Digits (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   8 Feb, 2022
 */

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        int temp = 0;
        while (true) {
            temp += num % 10;
            num /= 10;
            if (num == 0) {
                num = temp;
                temp = 0;
                if (num < 10)
                    return num;
            }
            // cout << temp << " " << num << "\n";
        }
    }
};
