/**
 * Title:  Shortest Subarray with Sum at Least K (Leetcode Hard 862)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, November, 2024
 * Method: Maintain a monotic increasing array to store the prefix sum and its end index, when current sum <= its top element's prefix sum, it means we can only get sum < 0 by this top element's index, so we remove it.
 *         Then we use binary search to find the index of the last num (the closest index) <= current sum - k, if it exists, we update the answer.
 * Result: Time complexity O(nlogn). Space complexity O(n).
 */

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n + 1;
        vector<pair<long long, int>> mono_inc; // prefix-sum, end-idx
        mono_inc.emplace_back(make_pair(0, -1));

        function<int(long long)> bs = [&](long long v) { // find index of the last num <= v
            int l = 0, r = mono_inc.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (mono_inc[mid].first <= v) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l - 1;
        };

        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            while (!mono_inc.empty() && s <= mono_inc.back().first) {
                mono_inc.pop_back();
            }
            mono_inc.emplace_back(make_pair(s, i));
            int id = bs(s - k);
            // cout << i << ", " << s << ": " << id << "\n";
            if (id >= 0) {
                ans = min(ans, i - mono_inc[id].second);
            }
        }

        return (ans == n + 1) ? -1 : ans;
    }
};
