/**
 * Title:  Arithmetic Subarrays(Leetcode Medium 1630)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, November, 2023
 * Method: Calculate diff by maxi and min, use unordered_set to check whether every element is inside the set.
 * Result: Time complexity: O(mn), Space complexity: O(n)
 */

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m, true);
        for (int i = 0; i < m; i++) {
            int mini = 1e6;
            int maxi = -1e6;
            unordered_set<int> us;
            for (int j = l[i]; j <= r[i]; j++) {
                mini = min(nums[j], mini);
                maxi = max(nums[j], maxi);
                us.insert(nums[j]);
            }
            int s = r[i] - l[i] + 1;
            if ((maxi - mini) % (s - 1) != 0) {
                ans[i] = false;
                continue;
            }
            int diff = (maxi == mini) ? 0 : (maxi - mini) / (s - 1);
            if (diff != 0) {
                while (mini + diff <= maxi) {
                    if (us.find(mini + diff) == us.end()) {
                        ans[i] = false;
                        break;
                    }
                    mini += diff;
                }
            }
        }
        return ans;
    }
};
// 1,3,5,7,9

// 1 + (1 + 2) + (1 + 2 * 2) + (1 + 2 * 3) + (1 + 2 * 4)
// 1 * n + 2 * (1 + 2 + 3 + 4)
// 1 * n + 2 * (5 * 2)