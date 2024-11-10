/**
 * Title:  Shortest Subarray With OR at Least K II (Leetcode Medium 3097)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, November, 2024
 * Method: Remove maximum number calculation in solution1.cpp. Whenever res >= k, remove nums[l].
 * Result: Time complexity O(nlog2m). Space complexity O(1). m = max(nums[i]).
 */

class Solution {
public:
    void setBit(vector<int>& freq, int v) {
        int b = 0;
        while (v > 0) {
            freq[b] += (v & 1);
            v >>= 1;
            b++;
        }
    }
    vector<int> getSetBit(int v) {
        vector<int> ans;
        int b = 0;
        while (v > 0) {
            if (v & 1) {
                ans.emplace_back(b);
            }
            b++;
            v >>= 1;
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) return 1;
        int n = nums.size();
        int l = 0;
        int res = 0; // [l, r]
        vector<int> freq(32, 0);
        int ans = n + 1;
        for (int r = 0; r < n; r++) {
            res |= nums[r];
            setBit(freq, nums[r]);
            while (res >= k) {
                ans = min(ans, r - l + 1);
                auto ones = getSetBit(nums[l]);
                for (int& one: ones) {
                    freq[one]--;
                    if (freq[one] == 0)
                        res ^= (1 << one);
                }
                l++;
            }
        }
        return (ans == n + 1) ? -1 : ans;
    }
};

