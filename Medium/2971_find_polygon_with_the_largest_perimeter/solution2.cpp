/**
 * Title:  Find Polygon With the Largest Perimeter (Leetcode Medium 2971)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, February, 2024
 * Method: Use priority_queue to sort the numers then use accumulate to get the sum. Then traverse the array from the end to find the largest perimeter.
 * Result: Time complexity O(nlogn), space complexity O(n).
 */

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios::sync_with_stdio(false);
        priority_queue<int> q(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        while (q.size() > 2) {
            auto t = q.top();
            if (sum - t > t) return sum;
            sum -= t;
            q.pop();
        }
        return -1;
    }
};
