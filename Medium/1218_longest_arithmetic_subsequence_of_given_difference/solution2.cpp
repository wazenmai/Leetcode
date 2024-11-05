/**
 * Title:  Longest Arithmetic Subsequence of Given Difference (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, November, 2024
 * Method: Use dp array to store the length of longest subsequence of difference whose last element is arr[i]. Use unordred_map to store the index of element which has longest subsequence of difference whose last element is `key`.
 * Result: O(n) time complexity, O(n) space complexity
 */

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, 1);
        unordered_map<int, int> m; // num: id
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int org = dp[i];
            if (m.find(arr[i] - difference) != m.end()) {
                dp[i] = max(dp[i], dp[m[arr[i] - difference]] + 1);
            }
            ans = max(ans, dp[i]);
            if (m.find(arr[i]) == m.end()) {
                m[arr[i]] = i;
            } else if (dp[m[arr[i]]] < dp[i]) {
                m[arr[i]] = i;
            }
        }
        return ans;
    }
};

// 1,5,7,8,5,3,4,2,1
// dp[i] = longest subsequence of difference whose last element is i
// dp[i] = 1 + dp[i - k]
