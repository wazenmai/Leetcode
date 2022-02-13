/**
 * Title:  Subsets (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Feb, 2022
 * Note:   Retidy the code
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            int m = (int)ans.size();
            for (int j = 0; j < m; j++) {
                auto temp = ans[j];
                temp.emplace_back(nums[i]);
                ans.emplace_back(temp);
            }
            vector<int> one_num(1, nums[i]);
            ans.emplace_back(one_num);
        }
        vector<int> temp(0);
        ans.emplace_back(temp);
        return ans;
    }
};
