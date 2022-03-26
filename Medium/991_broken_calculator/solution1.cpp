/**
 * Title:  Broken Calculator (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, Mar, 2022
 * Method: From target to startValue, only even number && target > startValue can divisible by 2
 */

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue == target)
            return 0;
        int ans = 0;
        while (target != startValue) {
            // cout << target << " ";
            if ((target & 1) || target < startValue) {
                target += 1;
                ans++;
            } else {
                target /= 2;
                ans++;
            }
        }
        return ans;
    }
};
