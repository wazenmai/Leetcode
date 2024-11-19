/**
 * Title:  Maximum Sum of Distinct Subarrays With Length K (Leetcode Medium 2461)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, November, 2024
 * Method: Sliding window, use an array to store the count of each elmenet. Use dup to record the number of duplicate elements. If there is no duplicate, update the answer.
 * Result: Time complexity O(n), space complexity O(n). // n is the number of elements in the array.
 */

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int cnt[100001] = {0};
        long long s = 0;
        int dup = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            s += nums[i];
            cnt[nums[i]]++;
            if (cnt[nums[i]] >= 2) dup++;
        }
        long long ans = (dup) ? 0 : s;
        for (int i = k; i < n; i++) {
            s -= nums[i - k];
            cnt[nums[i - k]]--;
            if (cnt[nums[i - k]] > 0) dup--;
            s += nums[i];
            cnt[nums[i]]++;
            if (cnt[nums[i]] >= 2) dup++;
            ans = (dup) ? ans : max(ans, s);
        }
        return ans;
    }
};
