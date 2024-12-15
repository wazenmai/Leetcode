/**
 * Title:  Continuous Subarrays (Leetcode Medium 2762)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, December, 2024
 * Method: Use multiset (allow duplicate elements) to store the elements in the window. We can erase the element in the set by using the iterator, and get max and min value from .begin() and .rbegin().
 * Result: Time complexity is O(nlogn), space complexity is O(n). n is the number of elements in the array.
 */

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> s;
        int n = nums.size();
        int l = 0;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            s.insert(nums[r]);
            while (l < n && !s.empty() && (abs(*s.begin() - *s.rbegin()) > 2)) {
                s.erase(s.find(nums[l]));
                l++;
            }
            ans += (r - l + 1);
            // cout << l << "," << r << ": " << r - l + 1 << "\n";
        }
        return ans;
    }
};
