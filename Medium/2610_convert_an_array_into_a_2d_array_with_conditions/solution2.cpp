/**
 * Title:  Convert an Array Into a 2D Array With Conditions (Leetcode Medium 2610)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Janurary, 2024
 * Method: Use unordered_map to avoid counting unnecessary elements.
 * Result: Time complexity O(nlogn (add) + nm), Space complexity O(m) // m is the range of nums 
 */

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        int max_num = 0;
        for (int& num: nums) {
            m[num]++;
            max_num = max(max_num, m[num]);
        }
        vector<vector<int>> ans(max_num);
        for (int i = 0; i < max_num; i++) {
            for (auto it = m.begin(); it != m.end(); it++) {
                if (it->second != 0) {
                    ans[i].emplace_back(it->first);
                    it->second--;
                }
            }
        }
        return ans;
    }
};
