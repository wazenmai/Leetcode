/**
 * Title:  Maximum Ice Cream Bars (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, August, 2023
 * Method: Math. From the rules, we know that the number can not greater than next pos's number, so we iterate from the last position.
 *         Use last_num to record the biggest number we can accept. If this num can divided by last_num, then ans += (nums[i] / last_num - 1).
 *         If not, then we need to make this last_num as big as possible. last_num = nums[i] / (nums[i] / last_num + 1).
 */

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int last_num = nums[n - 1];
        // cout << "pos " << n - 1 << ": " << last_num << "\n";
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > last_num) {
                int m = nums[i] % last_num;
                if (m > 0) {
                    int r = nums[i] / last_num + 1;
                    last_num = nums[i] / r;
                    ans += (r - 1);
                } else {
                    ans += (nums[i] / last_num - 1);
                }
            } else {
                last_num = nums[i];
            }
            // cout << "pos " << i << ": " << last_num << ", " << ans << "\n";
        }
        return ans;
    }
};

// 881 -> 220 220 220 221 (3)
// [205, 205, 205, 206, 220, 220, 220, 221, 275]
// 881 / 275 = 3
// 821 
// 821 / 165 = 3