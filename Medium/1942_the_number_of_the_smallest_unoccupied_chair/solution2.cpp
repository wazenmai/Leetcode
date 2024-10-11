/**
 * Title:  The Number of the Smallest Unoccupied Chair (Leetcode Medium 1942)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, October, 2024
 * Method: Use min heap to store the end time and chiar id of the friend. Use another min heap to store the available chair id to accelerate efficiency of finding available chair.
 * Result: Time Complexity: O(nlogn), Space Complexity: O(n)
 */

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        for (int i = 0; i < n; i++) {
            times[i].emplace_back(i);
        }
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (end time, chair id) people min heap
        priority_queue<int, vector<int> , greater<int>> chair; // min heap
        int st = 0;
        int sit;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first <= times[i][0]) {
                chair.push(pq.top().second);
                pq.pop();
            }
            if (!chair.empty()) {
                sit = chair.top();
                chair.pop();
            } else {
                sit = st;
                st++;
            }
            if (times[i][2] == targetFriend) break;
            pq.push(make_pair(times[i][1], sit));
        }
        return sit;
    }
};
