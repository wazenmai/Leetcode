/**
 * Title:  Convert an Array Into a 2D Array With Conditions (Leetcode Medium 2610)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Janurary, 2024
 * Method: Use vector to count the number of each element and the max and min range. The row of the answer is the max number of the same element.
 * Result: Time complexity O(n), Space complexity O(n) // If not count the answer space
 */

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> cnt(201, 0);
        int max_num = 0;
        int num_max = 0, num_min = 1000;
        for (int& num: nums) {
            cnt[num]++;
            max_num = max(max_num, cnt[num]);
            num_max = max(num, num_max);
            num_min = min(num, num_min);
        }
        vector<vector<int>> ans(max_num);
        for (int i = 0; i < max_num; i++) {
            for (int j = num_min; j <= num_max; j++) {
                if (cnt[j] > 0) {
                    ans[i].emplace_back(j);
                    cnt[j]--;
                }
            }
        }
        return ans;
    }
};
