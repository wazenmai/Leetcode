/**
 * Title: Minimum Number of Operations to Make Array Continuous (Leetcode Hard 2009)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, October, 2023
 * Method: First get the unique sorted array, then iterate every element e and find its maximum e + n - 1, 
 *         use binary search to find the upper bound index, then we can get the answer of operation by assuming the element e is the first element of the array
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
            // cout << i << "," << s << ": " << e << ",";
            auto it = upper_bound(uni_nums.begin(), uni_nums.end(), e);
            int idx = distance(uni_nums.begin(), it);
            // cout << n - (idx - i) << "\n"; 
            ans = min(ans, n - (idx - i));
        }
        return ans;
    }
};
