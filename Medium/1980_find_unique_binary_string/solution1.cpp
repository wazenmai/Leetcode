/**
 * Title:  Find Unique Binary String (Leetcode Medium 1980)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, November, 2023
 * Method: Since there are n numbers of n bits, we can make ans number's i-bit is differnt from i-th number's i-bit.
 */

class Solution {
public:
    string opposite(char a) {
        if (a == '0') return "1";
        return "0";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += opposite(nums[i][i]);
        }
        return ans;
    }
};
