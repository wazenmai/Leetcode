/**
 * Title:  Last Stone Weight (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, April, 2022
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto& x : stones)
            pq.push(x);
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int weight = abs(x - y);
            // cout << x << ", " << y << ": " << weight << "\n";
            if (weight > 0)
                pq.push(weight);
        }
        return (pq.empty()) ? 0 : pq.top();
    }
};
