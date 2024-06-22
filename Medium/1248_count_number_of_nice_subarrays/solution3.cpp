/**
 * Title:  Count Number of Nice Subarrays (Leetcode Medium 1248)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, June, 2024
 * Method: Use a vector to store the indices of odd numbers, and then use a sliding window to find the number of nice subarrays.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1)
                odd.emplace_back(i);
        }
        int ans = 0;
        int m = odd.size();
        for (int i = 0; i < m - k + 1; i++) {
            int st = odd[i];
            int ed = odd[i + k - 1];
            int last_st = (i == 0) ? 0 : odd[i - 1] + 1;
            int next_ed = (i + k == m) ? n - 1 : odd[i + k] - 1;
            
            ans += (st - last_st + 1) * (next_ed - ed + 1);
            // cout << "(st,ed)=(" << st << "," << ed << "), (last_st,next_ed)=(" << last_st << "," << next_ed << "): " << ans << "\n";
        }
        return ans;
    }
};

// 1 1 2 1 1, k=3
// 0 1   3 4, odd=4
// 0 1   2 3

// 2 2 1 2 1 2 1 2 1, k=3
//     2   4   6   8
// st,ed=(2, 6) last_st, next_ed(0, 7)
