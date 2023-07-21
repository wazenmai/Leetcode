/**
 * Title:  Number of Longest Increasing Subsequence (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, July, 2023
 */

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto a: v) {
            cout << a << " ";
        }
        cout << "\n";
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int ll = 1; // longest length
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        ll = max(dp[i], ll);
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) { // another subseq with same length ending at i
                        cnt[i] += cnt[j];

                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            // cout << dp[i] << " ";
            if (dp[i] == ll)
                ans += cnt[i];
        }  
        return ans;
    }
};

/*
dp[i]: the length of the LIS ending at index i
*/
