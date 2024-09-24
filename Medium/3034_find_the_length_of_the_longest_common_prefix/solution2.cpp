/**
 * Title:  Find the Length of the Longest Common Prefix (Leetcode Medium 3043)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, September, 2024
 * Method: Push all prefix in arr1 into a set, then iterate arr2 to find the longest common prefix.
 * Result: Time complexity O(nlog_10(n) + mlog_10(m)), Space complexity O(nlog_10(n)), where log_10(n) is the number of digits in n.
 */

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        unordered_set<int> us;
        for (int i = 0; i < n; i++) {
            int num = arr1[i];
            while (num > 0) {
                us.insert(num);
                num /= 10;
            }
        }
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int num = arr2[j];
            int digit = floor(log10(num)) + 1;
            while (num > 0 && ans < digit) {
                if (us.find(num) != us.end()) {
                    ans = max(ans, (int)floor(log10(num)) + 1);
                    break;
                }
                num /= 10;
            }
        }
        return ans;
    }
};
