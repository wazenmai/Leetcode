/**
 * Title:  Maximum Beauty of an Array After Applying Operation (Leetcode Medium 2779)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, December, 2024
 * Method: Prefix sum. Use a range array to record the number of elements in the range of [num - k, num + k].
 * Result: Time complexity is O(n+m), space complexity is O(1). m is the number range of the nums.
 */

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> range(300010, 0);
        int l = 300010, r = 0;
        for (auto& num: nums) {
            range[num - k + 100000]++;
            range[num + k + 100001]--;
            l = min(num - k + 100000, l);
            r = max(num + k + 100000 + 1, r);
        }
        int ans = 1;
        int cur = 0;
        // cout << l << "," << r << "\n";
        for (int i = l; i <= r; i++) {
            cur += range[i];
            // cout << cur << ", ";
            ans = max(ans, cur);
        }
        return ans;
    }
};
// 1246