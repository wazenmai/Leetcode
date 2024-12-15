/**
 * Title:  Continuous Subarrays (Leetcode Medium 2762)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, December, 2024
 * Method: We can use sliding window to calculate the valid subarray, but we need to maintain the maximum value and minimum value of current window. Two heap to store min value and max value.
 * Result: Time complexity is O(nlogn), space complexity is O(n). n is the number of elements in the array.
 */

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = (int)nums.size();
        // cout << n << "\n";
        int r = 1;
        priority_queue<pair<int, int>> max_heap; // value, idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // value, idx
        max_heap.push(make_pair(nums[0], 0));
        min_heap.push(make_pair(nums[0], 0));
        for (int l = 0; l < n; l++) {
            if (max_heap.empty() && min_heap.empty()) {
                max_heap.push(make_pair(nums[l], l));
                min_heap.push(make_pair(nums[l], l));
                r = l;
            }
            if (!max_heap.empty() && max_heap.top().first - min_heap.top().first > 2) {
                ans++;
                continue;
            }
            while (r < n && !max_heap.empty() && (abs(max_heap.top().first - nums[r]) <= 2) && (abs(min_heap.top().first - nums[r]) <= 2)) {
                max_heap.push(make_pair(nums[r], r));
                min_heap.push(make_pair(nums[r], r));
                r++;
            }
            // if (l >= 50000) {
            //     if (!max_heap.empty()) {
            //         cout << "max: " << max_heap.top().first << "," << max_heap.top().second << ", min: " << min_heap.top().first << "," << min_heap.top().second << "- (l, r): ";
            //     }
            //     cout << l << ", " << r << ": " << nums[l] << "\n";
            // }
            ans += (r - l);
            while (!max_heap.empty() && max_heap.top().second <= l) {
                max_heap.pop();
            }
            while (!min_heap.empty() && min_heap.top().second <= l) {
                min_heap.pop();
            }
        }
        return ans;
    }
};
