/**
 * Title:  Minimum Limit of Balls in a Bag (Leetcode Medium 1760)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, December, 2024
 * Method: Binary search the maximum number in the bag. If we want the maximum number = mid, then we need (num - 1) / mid operations to get the number.
 * Result: Time complexity is O(nlogn + nlogm), space complexity is O(1). n is the size of nums, m is the maximum number in nums.
 */

class Solution {
public:
    bool check(vector<int>& nums, int maxOperations, int mid) {
        int op = 0;
        for (auto& num: nums) {
            if (num <= mid) break;
            op += ((num - 1) / mid);
            if (op > maxOperations) break;
        }
        // cout << "check " << mid << ": " << op << "\n";
        return (op > maxOperations) ? false : true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        
        int l = 1, r = nums[0] + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, maxOperations, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

// 100 -> 33
// 33 67
// 33 33 34
// 11 -> 3
// 3 8
// 3 3 5 -> 3 3 3 2
// 12
// 8 -> 2 (3)
// 2 6, 2
// 9->2
