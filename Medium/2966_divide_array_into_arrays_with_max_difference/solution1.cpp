/**
 * Title:  Divide Array Into Arrays With Max Difference (Leetcode Medium 2966)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, February, 2024
 */

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            // cout << nums[i] << " " << nums[i + 1] << " " << nums[i + 2] << "\n";
            if (nums[i + 2] - nums[i] > k) {
                vector<vector<int>> p;
                return p;
            }
            vector<int> v{nums[i], nums[i + 1], nums[i + 2]};
            ans.emplace_back(v);
        }
        return ans;
    }
};
