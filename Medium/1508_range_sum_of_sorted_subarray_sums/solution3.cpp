/**
 * Title:  Range Sum of Sorted Subarray Sums (Leetcode Medium 1508)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, August, 2024
 * Method: Calulate the sum of left-th smallest subarrays to right-th smallest arrays is equal to the sum of first `right` smallest subarrays - the sum of first `left - 1` smallest subarrays.
    *      We can use binary search to find the sum of first `k` smallest subarrays. By setting l = min(nums) and r = sum(nums), we can use `helper` to calculate # of subarrays and its sum whose sum <= mid.
    *      If # of subarrays >= k, we can set r = mid - 1, otherwise l = mid + 1.
    *      `helper` function is used to calculate # of subarrays and its sum whose sum <= target. We use two pointers to maintain a window whose sum <= target.
    *      By using two pointers, we can calculate current window sum `cur` and all subarrays sum `window`, if cur > target, we move the left pointer to right until cur <= target. `cnt` records # of subarrays, `total` records the sum of subarrays.
 * Result: Time complexity O(nlogs), Space complexity O(1). // s = sum of `nums`.
 */

class Solution {
private:
    int mod = 1e9 + 7;
public:
    pair<int, long long> helper(vector<int>& nums, int n, int target) {
        // find (# of subarray, sum of subararys) in nums whose sum <= target
        int cnt = 0;
        long long cur = 0; // current window sum
        long long window = 0; // 
        long long total = 0;
        for (int st = 0, ed = 0; ed < n; ed++) { // start and end index of window
            cur += nums[ed];
            window += nums[ed] * (ed - st + 1); // ?
            while (cur > target) {
                window -= cur;
                cur -= nums[st++];
            }
            cnt += (ed - st + 1);
            total += window;
        }
        return make_pair(cnt, total);
    }
    int sumOfFirstK(vector<int>& nums, int n, int k) { // sum of first k smallest "subarray" sums
        int l = *min_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while (l <= r) {
            int mid = (l + r) / 2;
            // calculate # of subarrays with sum <= mid, also record the sum of these subarrays
            auto p = helper(nums, n, mid); // cnt, sum
            if (p.first >= k) { // find whether we have 
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        auto [cnt, sum] = helper(nums, n, l); // # of subarrays whose sum <= l, sum of those subarrays
        // There may be more subarrays with the same sum of left
        // so we need to make sure our sum is only calculated by first `k` smallest subarrys
        return (sum - l * (cnt - k)) % mod;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int ans = (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) % mod;
        return (ans + mod) % mod;
    }
};

// idx  0 1 2 3
// nums 1 2 3 4
// right = 5, left = 1 -> sumOfFirstK(5) - sumOfFirstK(0) = sum(1, 2, 3, 4, 5)

// let n = size of `nums`, s = total sum of `nums`
// Time complexity O(nlogs)
// - total binary search space  = s, each binary search O(logs) // run logs time of search
// - helper takes O(n)
// Space complexity O(1)

