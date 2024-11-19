/**
 * Title:  Maximum Sum of Distinct Subarrays With Length K (Leetcode Medium 2461)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, November, 2024
 * Method: Sliding window, use an unordered_set to store the distinct elements in the window. If size >= k or the element is already in the set, erase the element from the set and update the sum. Use p to record the start of the window.
 * Result: Time complexity O(n), space complexity O(n). // n is the number of elements in the array.
 */

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> us;
        long long ans = 0, s = 0;
        int i = 0;
        int p = 0;
        while (i < n) {
            while (us.size() >= k) {
                us.erase(nums[p]);
                s -= nums[p];
                p++;
            }
            if (us.find(nums[i]) == us.end()) {
                us.insert(nums[i]);
                s += nums[i];
            } else {
                while (us.find(nums[i]) != us.end()) {
                    us.erase(nums[p]);
                    s -= nums[p];
                    p++;
                }
                us.insert(nums[i]);
                s += nums[i];
            }
            if (us.size() == k) {
                ans = max(ans, s);
            }
            // cout << i << ", " << s << " " << ans << ", us: " << us.size() << "\n";
            i++;
        }
        return ans;
    }
};
