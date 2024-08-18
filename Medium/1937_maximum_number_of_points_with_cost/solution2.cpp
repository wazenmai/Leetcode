/**
 * Title:  Maximum Number of Points With Cost (Leetcode Medium 1937)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, August, 2024
 * Method: When iterate from right to left, we reuse `left` to store the maximum points.
 * Result: Time complexity O(n*2m) = O(nm), space complexity O(3m) = O(m).
 */

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> pre(m, 0);
        // initialize pre
        for (int j = 0; j < m; j++) {
            pre[j] = points[0][j];
        }
        
        for (int i = 1; i < n; i++) {
            vector<long long> left(m, 0);
            vector<long long> right(m, 0);
            left[0] = pre[0];
            for (int j = 1; j < m; j++) {
                left[j] = max(left[j - 1] - 1, pre[j]);
            }
            right[m - 1] = pre[m - 1];
            left[m - 1] = max(left[m - 1], right[m - 1]) + points[i][m - 1];
            for (int j = m - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, pre[j]);
                left[j] = max(left[j], right[j]) + points[i][j];
            }
            pre = left;
        }

        long long ans = 0;
        for (int j = 0; j < m; j++) {
            ans = max(ans, pre[j]);
        }
        return ans;
    }
};

// cur[i] = max(pre[j] - abs(j - 1)) // j = 0 ~ m

// cur[i] = max(left[i], right[i]) + points[r][i]
