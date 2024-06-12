/**
 * Title:  Sort Colors (Leetcode Medium 75)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, June, 2024
 * Method: Throw 0 to left, 2 to right. One can also use libaray sort.
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int i = 0;
        while (i < n) {
            while (r >= 0 && nums[r] == 2) r--;
            while (l < n && nums[l] == 0) l++;
            while (i < n && (i < l || nums[i] == 1)) i++;
            if (r < 0 || i > r || l == n) break;
            // cout << "l: (" << l << "," << nums[l] << "),i: (" << i << "," << nums[i] << "), r: (" << r << "," << nums[r] << ")\n";    
            if (nums[i] == 0) {
                int temp = nums[l];
                nums[l] = nums[i];
                nums[i] = temp;
            } else if (nums[i] == 2) {
                int temp = nums[r];
                nums[r] = nums[i];
                nums[i] = temp;
            }
        }
    }
};
