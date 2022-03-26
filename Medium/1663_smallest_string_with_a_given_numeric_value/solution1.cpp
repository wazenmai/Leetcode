/**
 * Title:  Smallest String with A Given Numeric Value (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2022
 */

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            ans += "a";
            k--;
        }
        
        int i = n - 1;
        while (i >= 0 && k > 0) {
            if (k > 25) {
                ans[i] = 'z';
                k -= 25;
                i--;
            } else {
                ans[i] = 'a' + k;
                k = 0;
                i--;
            }
        }
        return ans;
    }
};
