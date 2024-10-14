/**
 * Title:  Maximal Score After Applying K Operations (Leetcode Medium 2530)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, October, 2024
 * Method: Optimized solution for solution1.cpp. Initialize heap with one line. If the top element is 1, we can add the rest of the elements to the score directly. We can get ceil(x/3) by (x+2)/3.
 * Result: Time complexity O(klogn). Space complexity O(n).
 */

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;
        for (int i = 0; i < k; i++) {
            score += pq.top();
            if (pq.top() == 1) {
                score += (k - 1 - i);
                break;
            }
            int temp = (pq.top() + 2) / 3;
            pq.pop();
            pq.push(temp);
        }
        return score;
    }
};