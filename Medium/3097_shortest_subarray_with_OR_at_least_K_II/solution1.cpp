/**
 * Title:  Shortest Subarray With OR at Least K II (Leetcode Medium 3097)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, November, 2024
 * Method: Sliding window. `setBit` accumulate frequency of 1-bit. `getSetBit` get the position of 1-bit in a number.
 *         When removing a number, we need to check its 1-bit and if the frequency of this bit is 0, we need to remove this bit from res.
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
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());
        if (max_num >= k) return 1;
        if (max_num <= k / 2) return -1;
        int l = 0;
        int res = 0; // [l, r]
        vector<int> freq(32, 0);
        int ans = n;
        for (int r = 0; r < n; r++) {
            res |= nums[r];
            setBit(freq, nums[r]);
            while (res >= k) {
                int temp = res;
                vector<int> temp_freq = freq;
                auto ones = getSetBit(nums[l]);
                for (int& one: ones) {
                    temp_freq[one]--;
                    if (temp_freq[one] == 0)
                        temp ^= (1 << one);
                }
                if (temp >= k) {
                    l++;
                    res = temp;
                    freq = temp_freq;
                } else {
                    break;
                }
            }
            if (res >= k) {
                ans = min(ans, r - l + 1);
            }
        }
        return (res >= k ) ? ans : -1;
    }
};


// 0123456
// 0010, 0001, 0011, 1000, 0011, k = 1010
// 0010, 0011, 0011, 1011
