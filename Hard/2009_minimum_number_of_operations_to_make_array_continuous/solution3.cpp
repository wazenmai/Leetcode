/**
 * Title: Minimum Number of Operations to Make Array Continuous (Leetcode Hard 2009)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, October, 2023
 * Method: Same as solution2.cpp, but use my own binary search function.
 * Result: Time Complexity O(nlogn), Space Complexity O(n)
 */

class Solution {
public:
    void printvec(vector<int>& nums) {
        for (int& e: nums) {
            cout << e << " ";
        }
        cout << "\n";
    }
    int bs(vector<int>& nums, int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> uni_nums(nums.begin(), unique(nums.begin(), nums.end()));
        // printvec(uni_nums);
        int ans = n;
        int m = uni_nums.size();
        for (int i = 0; i < m; i++) {
            int s = uni_nums[i];
            int e = s + n - 1;
            // cout << i << "," << s << ": " << e << " at ";
            int it = bs(uni_nums, m, e);
            // cout << it << ", ";
            // cout << n - (it - i) << "\n"; 
            ans = min(ans, n - (it - i));
        }
        return ans;
    }
};
