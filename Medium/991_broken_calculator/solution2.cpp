/**
 * Title:  Broken Calculator (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, Mar, 2022
 * Method: if target < startValue, it can only + 1
 */

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue == target)
            return 0;
        int ans = 0;
        while (target != startValue) {
            // cout << target << " ";
            if (target & 1) {
                target += 1;
                ans++;
            } else if (target > startValue){
                target /= 2;
                ans++;
            } else {
                ans += (startValue - target);
                target = startValue;
            }
        }
        return ans;
    }
};
