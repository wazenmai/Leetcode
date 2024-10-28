/**
 * Title:  Longest Square Streak in an Array (Leetcode Medium 2501)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, October, 2024
 * Method: Remove used element, since we start from the smallest number.
 * Result: Time complexity O(n). Space complexity O(n).
 */

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        unordered_set us(nums.begin(), nums.end());
        for (int i = 2; i * i <= 100000; i++) {
            int temp = 0;
            int num = i;
            while (num <= 100000 && us.find(num) != us.end()) {
                temp++;
                // cout << num << " " << temp << "\n";
                us.erase(num);
                if (num >= 330) break;
                num = num * num;
            }
            ans = max(temp, ans);
        }
        return (ans < 2) ? -1 : ans;
    }
};
