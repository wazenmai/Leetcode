/**
 * Title:  Count Number of Nice Subarrays (Leetcode Medium 1248)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, June, 2024
 * Method: Odd is 1, even is 0. Construct a prefix sum array to store the number of odd numbers before index i.
 * Result: TLE. Time complexity is O(n^2), space complexity is O(n).
 */

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1)
                prefix[i + 1] = prefix[i] + 1;
            else
                prefix[i + 1] = prefix[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (prefix[j] - prefix[i] == k) ans++;
                if (prefix[j] - prefix[i] > k) break;
            }
        }
        return ans;
    }
};
// 0 1 2 3 4 5 6 7 8 9
// 2,2,2,1,2,2,1,2,2,2
// 0 0 0 0 1 1 1 2 2 2 2

// 1 2 3 4
// 0 1 3 6 10
// 0 1 2 3 4
// prefix[i] - prefix[j] = sum[j ~ i-1]