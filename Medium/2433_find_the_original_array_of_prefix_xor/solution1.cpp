/**
 * Title:  Find The Original Array of Prefix Xor (Leetcode Medium 2433)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, October, 2023
 * Method: Use `temp` to record the xor result so far. The element tmep ^ num is the ans we want.
 * Result: Time Complexity O(n), Space Complexity O(n)
 */

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int temp = 0;
        for (int& num: pref) {
            int e = temp ^ num;
            temp ^= e;
            ans.emplace_back(e);
        }
        return ans;
    }
};

// temp = 101
// target 010
// 111