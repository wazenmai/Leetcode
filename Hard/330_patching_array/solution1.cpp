/**
 * Title:  Patching Array (Leetcode Hard 330)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, June, 2024
 */

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        long long next_num = 1;
        long long newn = n;
        int ans = 0;
        int s = nums.size();
        for (int i = 0; i < s; i++) {
            while (nums[i] > next_num && sum < newn) {
                sum += next_num;
                next_num = sum + 1;
                ans++;
            }
            sum += nums[i];
            next_num = sum + 1;
            if (sum >= newn) return ans;
        }
        while (sum < newn) {
            sum += next_num;
            next_num = sum + 1;
            ans++;
        }
        return ans;
    }
};
