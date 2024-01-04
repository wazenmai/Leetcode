/**
 * Title:  Minimum Number of Operations to Make Array Empty (Leetcode Medium 2870)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, Janurary, 2024
 * Method: Use unordered_map to store the number of each element.
 * Result: Time complexity: O(n), Space complexity: O(n)
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num: nums) {
            m[num]++;
        }
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1)
                return -1;
            else {
                int mod = it->second % 3;
                if (mod == 0) {
                    ans += (it->second / 3);
                } else if (mod == 1){
                    ans += 2;
                    it->second -= 4;
                    ans += (it->second / 3);
                } else {
                    ans += (it->second / 3) + 1;
                }
            }
        }
        return ans;
    }
};
