/**
 * Title:  Subarray Sum Equals k (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, Feb, 2022
 * Method: Only suitable for positive numbers
 * Result: Wrong Answer
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        queue<int> cont_arr;
        int temp_sum = 0;
        int ans = 0;
        for (auto& n : nums) {
            cont_arr.push(n);
            temp_sum += n;
            cout << n << " " << temp_sum << "\n";
            if (temp_sum == k) {
                ans++;
            }
            while (temp_sum > k) {
                temp_sum -= cont_arr.front();
                cont_arr.pop();
                if (temp_sum == k && !cont_arr.empty())
                    ans++;
            }
        }
        return ans;
    }
};
