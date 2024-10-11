/**
 * Title:  The Number of the Smallest Unoccupied Chair (Leetcode Medium 1942)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, October, 2024
 * Method: Use pq to store the end time and chiar id of the friend. Use an array to represent the chair. Each time a new friend comes, we first check pq to see if there is any chair available. Then iterate through chair array to find the smallest chair id.
 * Result: Time Complexity: O(nlogn + n^2) = O(n^2), Space Complexity: O(n)
 */

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        for (int i = 0; i < n; i++) {
            times[i].emplace_back(i);
        }
        // cout << n << "\n";
        // cout << "target: " << times[targetFriend][0] << ", " << times[targetFriend][1] << "\n";
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> chair(n, true);
        for (int i = 0; i < n; i++) {
            // cout << times[i][2] << " ";
            while (!pq.empty() && pq.top().first <= times[i][0]) {
                chair[pq.top().second] = true;
                pq.pop();
            }
            for (int j = 0; j <= i; j++) {
                if (chair[j]) {
                    chair[j] = false;
                    if (times[i][2] == targetFriend) return j;
                    pq.push(make_pair(times[i][1], j));
                    break;
                }
            }
        }
        return n - 1;
    }
};
