/**
 * Title:  Maximum Score of A Good Subarray (Leetcode Hard 1793)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, October, 2023
 * Method: Use two pointers to find the maximum score. Optimize the IO bound to be faster.
 * Result: Time Complexity O(n), Space Complexity O(1)
 */

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k, j = k;
        int n = nums.size();
        int min_num = nums[k];
        int ans = min_num;
        // cout << n << "\n";
        while (i >= 0 && j < n) {
            // cout << i << ", " << j << "\n";
            if (i > 0 && j < n - 1) {
                if (nums[j + 1] >= nums[i - 1]) {
                    j++;
                    min_num = min(min_num, nums[j]);
                } else {
                    i--;
                    min_num = min(min_num, nums[i]);
                }
            } else if (i > 0) {
                i--;
                min_num = min(min_num, nums[i]);
            } else if (j < n - 1) {
                j++;
                min_num = min(min_num, nums[j]);
            } else {
                break;
            }
            ans = max(ans, min_num * (j - i + 1));
        }
        return ans;
    }
};
