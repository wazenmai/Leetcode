/**
 * Title:  Maximum Length of a Concatenated String with Unique Characters (Leetcode Medium 1239)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, Janurary, 2024
 * Method: Use bit map to store the set of characters, and save all possible combination in dp list.
 * Result: Time complexity O(NM). Space complexity O(2^N)
 */

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int ans = 0;
        for (const string& s: arr) {
            int a = 0; // the set of characters
            int dup = 0; // check duplicate characters
            for (char c: s) {
                dup |= a & (1 << (c - 'a'));
                a |= 1 << (c - 'a');
            }
            if (dup > 0) continue; // duplicate characters in s

            for (int i = dp.size() - 1; i >= 0; i--) {
                if ((dp[i] & a) > 0) continue; // duplicate characters of s and dp[i]
                dp.emplace_back(dp[i] | a);
                ans = max(ans, __builtin_popcount(dp[i] | a)); // count 1 in dp[i] | a
            }
        }
        return ans;
    }
};

// N = # of strings in arr (arr.size()), M = max length of s
// Time complexity O(NM). Space complexity O(2^N)
