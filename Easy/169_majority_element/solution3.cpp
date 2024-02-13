/**
 * Title:  Majority Element (Leetcode Easy 169)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, February, 2024
 * Result: Time complexity O(nlogn), Space complexity O(n)
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        int base = (n & 1) ? n / 2 + 1 : n / 2;
        for (int& num: nums) {
            m[num]++;
            if (m[num] >= base)
                return num;
        }
        return 0;
    }
};
