/**
 * Title:  Maximum Number of Integers to Choose From a Range I (Leetcode Medium 2554)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, December, 2024
 * Method: First sort the banned. Then iterate the banned to find the maximum number of integers to choose from a range I.
 * Result: Time complexity is O(n + mlogm), space complexity is O(1). n = n, m = banned.size().
 */

class Solution {
public:
    void print(vector<int>& v) {
        for (auto& e: v) {
            cout << e << ",";
        }
        cout << "\n";
    }
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int num = 1;
        int m = banned.size();
        int sum = 0;
        int cnt = 0;
        // print(banned);
        for (int i = 0; i < m; i++) {
            if (i > 0 && banned[i] == banned[i - 1]) continue;
            // cout << num << "," << sum << "," << cnt << "\n";
            while (sum + num <= maxSum && num <= n && num != banned[i]) {
                sum += num;
                cnt++;
                num++;
            }
            if (num == banned[i]) num++;
            if (sum + num > maxSum) break;
        }
        // cout << "final: " << num << "," << sum << "," << cnt << "\n";
        while (sum + num <= maxSum && num <= n) {
            sum += num;
            cnt++;
            num++;
        }
        return cnt;
    }
};
