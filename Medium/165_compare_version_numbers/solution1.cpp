/**
 * Title:  Compare Version Numbers (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Feb, 2022
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1 = 0;
        int num2 = 0;
        int i = 0;
        int j = 0;
        int l1 = version1.length();
        int l2 = version2.length();
        while (i < l1 || j < l2) {
            while (i < l1 && version1[i] != '.') {
                num1 = num1 * 10 + version1[i] - '0';
                i++;
            }
            while (j < l2 && version2[j] != '.') {
                num2 = num2 * 10 + version2[j] - '0';
                j++;
            }
            // cout << "(" << i << ", " << j << "): " << num1 << ", " << num2 << "\n";
            if (num1 > num2)
                return 1;
            else if (num2 > num1)
                return -1;
            else {
                num1 = num2 = 0;
                i++;
                j++;
            }
        }
        return 0;
    }
};
