/**
 * Title:  Continuous Subarrays (Leetcode Medium 2762)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, December, 2024
 * Method: Monotonic queue. One to store min value (front...back), one to store max value (front...back). when current nums[r] is bigger than the smallest max value or the biggest min value, we pop_back() from the queue. We store the index instead of value. We move left by one step when the difference between the biggest min value and the smallest max value is bigger than 2.
 * Result: Time complexity is O(n), space complexity is O(n). n is the number of elements in the array.
 */

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> min_dq; // min ... max
        deque<int> max_dq; // max ... min
        long long ans = 0;
        int l = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            while (!max_dq.empty() && nums[max_dq.back()] < nums[r]) {
                max_dq.pop_back();
            }
            max_dq.push_back(r);
            while (!min_dq.empty() && nums[min_dq.back()] > nums[r]) {
                min_dq.pop_back();
            }
            min_dq.push_back(r);
            while (!min_dq.empty() && !max_dq.empty() && nums[max_dq.front()] - nums[min_dq.front()] > 2) {
                if (max_dq.front() < min_dq.front()) {
                    l = max_dq.front() + 1;
                    max_dq.pop_front();
                } else {
                    l = min_dq.front() + 1;
                    min_dq.pop_front();
                }
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
