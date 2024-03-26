/**
 * Title:  First Missing Positive (Leetcode Hard 41)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, March, 2024
 * Method: The answer must be in the range [1, n + 1]. Mark number out of range as -1, and swap the number to the correct position. If the number is already in the correct position, mark it as -1 (since it is duplicate number). Finally, find the position of first number that is -1.
 * Result: Time complexity O(n), Space complexity O(1).
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // cout << i << ", " << nums[i] << "\n";
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = -1;
            } else {
                while (nums[i] > 0 && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                    int id = nums[i] - 1;
                    int temp = nums[i];
                    nums[i] = nums[id];
                    nums[id] = temp;
                }
                int id = nums[i] - 1;
                if (id >= 0 && id != i && nums[id] == nums[i]) {
                    nums[i] = -1;
                }
                if (nums[i] == 0) nums[i] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) return i + 1;
        }
        return n + 1;
    }
};
