/**
 * Title: Minimum Number of Operations to Make Array Continuous (Leetcode Hard 2009)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, October, 2023
 * Result: Wrong Answer, Since I only consider the first and last element
 */

class Solution {
public:
    void printvec(vector<int>& nums) {
        for (int& e: nums) {
            cout << e << " ";
        }
        cout << "\n";
    }
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // printvec(nums);
        int n = nums.size();
        int rep = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                rep++;
            }
        }
        // cout << "rep: " << rep << "\n";
        // Use max as basic
        int order = nums[n - 1];
        int max_op = 0;
        int i = 0, j = n - 2;
        int temp_rep = rep;
        while (i < j) {
            // cout << i << "," << j << ": " << nums[j] << "," << order << "\n";
            while (rep > 0 && order - 1 > nums[j]) {
                rep--;
                order--;
                max_op++;
            }
            while (order - 1 > nums[j]) {
                i++; // turn nums[i] to order - 1
                max_op++;
                order--;
                if (i > j)
                    break;
            }
            order--;
            j--;
        }
        max_op += rep;
        // cout << "max_op: " << max_op << "\n";
        int min_op = 0;
        rep = temp_rep;
        i = 1, j = n - 1;
        order = nums[0];
        while (i < j) {
            // cout << i << "," << j << ": " << nums[i] << "," << order << "\n";
            while (rep > 0 && order + 1 < nums[i]) {
                rep--;
                order++;
                min_op++;
            }
            while (order + 1 < nums[i]) {
                j--; // turn nums[j] to order + 1
                order++;
                min_op++;
                if (i > j)
                    break;
            }
            order++;
            i++;
        }
        min_op += rep;
        // cout << "min_op: " << min_op << "\n";
        return min(min_op, max_op);
    }
};
