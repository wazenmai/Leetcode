/**
 * Title:  Majority Element II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, October, 2023
 * Method: Time complexity O(n), space complexity O(1)
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // The answer is at most 2 numbers
        int n = nums.size();
        vector<int> ans;
        int candidate1 = 0, count1 = 0;
        int candidate2 = 1, count2 = 0;
        for (int& num: nums) {
            // cout << count1 << " " << count2 << "\n";
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (int& num: nums) {
            if (num == candidate1) count1++;
            if (num == candidate2) count2++;
        }
        if (count1 > n / 3) ans.emplace_back(candidate1);
        if (count2 > n / 3) ans.emplace_back(candidate2);
        return ans;
    }
};
