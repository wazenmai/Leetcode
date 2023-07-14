/**
 * Title:  Longest Arithmetic Subsequence of Given Difference (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, July, 2023
 * Result: O(n) time complexity, O(n) space complexity
 */

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> m; // num, length of subsequence
        int ans = 1;
        for (int num: arr) {
            if (m.find(num - difference) == m.end()) {
                m[num] = 1;
            } else { // find
                m[num] = m[num-difference] + 1;
                ans = max(ans, m[num]);
            }
        }
        return ans;
    }
};
