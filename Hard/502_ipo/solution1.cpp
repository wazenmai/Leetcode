/**
 * Title:  IPO (Leetcode Hard 502)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, June, 2024
 * Method: First sort the vector of pairs by capital. Then use a priority queue to store the profits. Loop K times. In each loop, push the profits into the priority queue if the capital is less than or equal to the current capital. Finally, add the top of the priority queue to the capital and pop it.
 * Result: Time complexity O(nlogn + klogn), Space complexity O(n). n is the size of profits. k is the number of projects we can complete.
 */

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = make_pair(capital[i], profits[i]);
        }
        sort(v.begin(), v.end()); // capital from small to large

        priority_queue<int> pq;
        int i = 0;

        for (int j = 0; j < k; j++) {
            while (i < n && v[i].first <= w) {
                pq.push(v[i].second);
                i++;
            }
            if (pq.empty()) break;

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
