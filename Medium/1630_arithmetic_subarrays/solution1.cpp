/**
 * Title:  Arithmetic Subarrays(Leetcode Medium 1630)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, November, 2023
 * Method: Naive soluion
 * Result: Time complexity: O(mnlogn), Space complexity: O(n)
 */

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m, true);
        for (int i = 0; i < m; i++) {
            // cout << i << "," << l[i] << "~" << r[i] << "\n";
            vector<int> temp;
            for (int j = l[i]; j <= r[i]; j++) {
                temp.emplace_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            if (temp.size() > 2) {
                int diff = temp[1] - temp[0];
                for (int j = 2; j < temp.size(); j++) {
                    if (temp[j] - temp[j - 1] != diff) {
                        ans[i] = false;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
