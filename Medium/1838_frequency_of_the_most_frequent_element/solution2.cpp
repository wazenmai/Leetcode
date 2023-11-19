/**
 * Title:  Frequency of the Most Frequent Element (Leetcode Medium 1838)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, November, 2023
 * Method: Use binary search to get the left index given right.
 * Result: Time complexity O(nlogn), space complexity O(n)
 */

class Solution {
public:
    int check (int i, int k, vector<int>& nums, vector<long>& prefix) {
        int target = nums[i];
        int left = 0, right = i;
        int best = i;
        while (left <= right) {
            int mid = (left + right) / 2;
            long cnt = i - mid + 1; // number of elements in the window
            long finalSum = cnt * target; // the window sum
            int originalSum = prefix[i] - prefix[mid] + nums[mid];
            int require = finalSum - originalSum;
            if (require > k) {
                left = mid + 1;
            } else {
                best = mid;
                right = mid - 1;
            }
        }
        return i - best + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<long> prefix;
        prefix.emplace_back(nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            prefix.emplace_back(nums[i] + prefix.back());
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, check(i, k, nums, prefix));
        }
        return ans;
    }
};
