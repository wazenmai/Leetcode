/**
 * Title:  Candy (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, September, 2023
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n;
        vector<int> candy(n, 1);

        // 0 ~ n-1
        if (n > 1 && ratings[0] > ratings[1]) {
            ans += 1;
            candy[0] = 2;
        }
        // cout << "(0," << candy[0] << ") ";
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
                ans += (candy[i - 1]);
            }
            // cout << "(" << i << "," << candy[i] << ") ";
        }
        // cout << "\n";
        // n-1 ~ 0
        if (n > 1 && ratings[n - 1] > ratings[n - 2] && candy[n - 1] <= candy[n - 2]) {
            ans += (candy[n - 2] + 1 - candy[n - 1]);
            candy[n - 1] = candy[n - 2] + 1;
        }
        // cout << "(" << n - 1 << "," << candy[n - 1] << ") ";
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
                ans += (candy[i + 1] + 1 - candy[i]);
                candy[i] = candy[i + 1] + 1;
            }
            //  cout << "(" << i << "," << candy[i] << ") ";
        }
        return ans;
    }
};
