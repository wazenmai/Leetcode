/**
 * Title:  Set Mismatch (Leetcode Easy 645)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Janurary, 2024
 * Method: Use cnt to find the missing number
 * Result: Time complexity O(nlogn).
 */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2);
        int cnt = 1;
        if (nums[0] != cnt) {
            ans[1] = cnt;
        }
        cnt++;
        for (int i = 1; i < nums.size(); i++) {
            // cout << i << ", " << nums[i] << " " << cnt << "\n";
            if (nums[i] == nums[i - 1]) {
                ans[0] = nums[i];
            }
            if (nums[i] != cnt && nums[i - 1] != cnt) {
                ans[1] = cnt;
            }
            cnt++;
        }
        return ans;
    }
};
// 1 1
// 2 2
// 2 3 3 4 
