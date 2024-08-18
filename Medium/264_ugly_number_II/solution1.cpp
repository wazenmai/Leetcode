/**
 * Title:  Ugly Number II (Leetcode Medium 264)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, August, 2024
 * Method: Use priority queue to store the ugly numbers. The top element of the priority queue is the smallest ugly number.
 * Result: Time complexity is O(nlogn), space complexity is O(n).
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        for (int i = 0; i < n - 1; i++) {
            auto num = pq.top();
            pq.pop();
            while (!pq.empty() && num == pq.top())
                pq.pop();
            pq.push(num * 2);
            pq.push(num * 3);
            pq.push(num * 5);
        }
        return (int)pq.top();
    }
};
