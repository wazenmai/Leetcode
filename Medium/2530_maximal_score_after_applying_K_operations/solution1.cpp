/**
 * Title:  Maximal Score After Applying K Operations (Leetcode Medium 2530)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, October, 2024
 * Method: Use max-heap to get maximal element in each operation.
 * Result: Time complexity O(klogn). Space complexity O(n).
 */

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto num: nums) {
            pq.push(num);
        }
        long long score = 0;
        for (int i = 0; i < k; i++) {
            score += pq.top();
            int temp = pq.top() / 3;
            if (pq.top() % 3 >= 1)
                temp++;
            pq.pop();
            pq.push(temp);
        }
        return score;
    }
};
