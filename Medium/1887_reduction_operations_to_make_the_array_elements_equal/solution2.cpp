/**
 * Title:  Reduction Operations to Make the Array Elements Equal (Leetcode Medium 1887)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, November, 2023
 * Method: Sort the array to get the order, level = the order of the number, which is the # of operations it need to reduce.
 * Result: Time complexity O(nlogn), space complexity O(n)
 */

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int level = 0;
        int largest = mini;
        int i = 0;
        int ans = 0;
        while (i < n && nums[i] == mini) {
            i++;
        }
        if (i == n) return 0;

        while (i < n) {
            if (nums[i] > largest) {
                largest = nums[i];
                level++;
                ans += level;
            } else {
                ans += level;
            }
            i++;
        }
        return ans;
    }
};
