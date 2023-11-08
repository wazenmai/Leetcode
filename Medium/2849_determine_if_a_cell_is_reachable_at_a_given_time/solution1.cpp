/**
 * Title:  MDetermine if a Cell Is Reachable at a Given Time (Leetcode Medium 2849)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, November, 2023
 * Method: Need to consider the special case: sx == fx && sy == fy && t == 1
 */

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy && t == 1) return false;
        int need = max(abs(fx - sx), abs(fy - sy));
        if (need <= t)
            return true;
        return false;
    }
};
