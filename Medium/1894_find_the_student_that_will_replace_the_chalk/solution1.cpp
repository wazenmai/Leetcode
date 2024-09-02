/**
 * Title:  Find the Student that Will Replace the Chalk (Leetcode Medium 1894)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, September, 2024
 */

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        int n = chalk.size();
        for (int i = 0; i < n; i++) {
            k -= chalk[i];
            total += chalk[i];
            if (k < 0) return i;
        }
        k = k % total;
        for (int i = 0; i < n; i++) {
            k -= chalk[i];
            if (k < 0) return i;
        }
        return 0;
    }
};
