/**
 * Title:  Maximum Number of Points With Cost (Leetcode Medium 1937)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, August, 2024
 * Method: Calculate the maximum points we can get from previous row. Two directions: left-to-right and right-to-left. The final point we can get from (i, j) is cur[j] = max(leftmax[j], rightmax[j]) + points[i][j]
 * Result: Time complexity O(n*3m) = O(nm), space complexity O(4m) = O(m).
 */

class Solution {
public:
    void print(vector<long long>& v) {
        for (auto& num: v) {
            cout << num << ",";
        }
        cout << "\n";
    }
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> pre(m, 0);
        // initialize pre
        cout << "0: ";
        for (int j = 0; j < m; j++) {
            pre[j] = points[0][j];
            cout << pre[j] << ",";
        }
        cout << "\n";
        
        for (int i = 1; i < n; i++) {
            vector<long long> cur(m, 0);
            vector<long long> leftmax(m, 0);
            vector<long long> rightmax(m, 0);
            leftmax[0] = pre[0];
            for (int j = 1; j < m; j++) {
                leftmax[j] = max(leftmax[j - 1] - 1, pre[j]);
            }
            // cout << i << ": \nleft: ";
            // print(leftmax);
            rightmax[m - 1] = pre[m - 1];
            for (int j = m - 2; j >= 0; j--) {
                rightmax[j] = max(rightmax[j + 1] - 1, pre[j]);
            }
            // cout << "right: ";
            // print(rightmax);
            // cout << "cur: ";
            for (int j = 0; j < m; j++) {
                cur[j] = max(leftmax[j], rightmax[j]) + points[i][j];
            }
            // print(cur);
            pre = cur;
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