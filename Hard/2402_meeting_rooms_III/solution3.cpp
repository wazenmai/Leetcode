/**
 * Title:  Meeting Rooms III (Leetcode Hard 2402)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, February, 2024
 * Method: Tidy the code.
 * Result: Time complexity O(mlogm + mlogn), space complexity O(n). Runtime 381 ms, Memory 115.3 MB.
 */

using ll = long long;

class Compare {
public:
    bool operator() (vector<ll>& a, vector<ll>& b) {
        // (room num, end time)
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] > b[1];
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::ios::sync_with_stdio(0); 
        std::cin.tie(0); 
        sort(meetings.begin(), meetings.end());
        priority_queue<vector<ll>, vector<vector<ll>>, Compare> q; // (room, end time)
        vector<int> room(n, 0); // # of meetings held in room
        vector<bool> empty(n, true); // whether this room is empty or not
        int m = meetings.size();
        ll timer = 0;
        ll empty_room = 0;
        for (int i = 0; i < m; i++) {
            while (!q.empty() && q.top()[1] <= meetings[i][0]) {
                empty[q.top()[0]] = true;
                empty_room = min(empty_room,  q.top()[0]);
                q.pop();
            }
            if (timer < meetings[i][0]) timer = meetings[i][0];
            q.push(vector<ll>{empty_room, timer - meetings[i][0] + meetings[i][1]});
            room[empty_room]++;
            empty[empty_room] = false;
            while (!empty[empty_room] && empty_room < n) {
                empty_room++;
            }
            if (empty_room == n) { // update timer to empty room
                timer = q.top()[1];
                while (!q.empty() && q.top()[1] <= timer) {
                    empty[q.top()[0]] = true;
                    empty_room = min(empty_room, q.top()[0]);
                    q.pop();
                }
            }
        }
        return max_element(room.begin(), room.end()) - room.begin();;
    }
};
