/**
 * Title:  Meeting Rooms III (Leetcode Hard 2402)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, February, 2024
 * Method: Add sync_with_stdio and cin.tie to speed up the input. 
 * Result: Time complexity O(mlogm + mlogn), space complexity O(n). Runtime 344 ms, Memory 115.21 MB.
 */

class Compare {
public:
    bool operator() (vector<long long>& a, vector<long long>& b) {
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
        priority_queue<vector<long long>, vector<vector<long long>>, Compare> q; // (room, end time)
        vector<int> room(n, 0); // # of meetings held in room
        vector<bool> empty(n, true); // whether this room is empty or not
        int m = meetings.size();
        long long timer = 0;
        long long empty_room = 0;
        for (int i = 0; i < m; i++) {
            if (q.size() == 0) { // no meeting now
                if (timer < meetings[i][0]) timer = meetings[i][0];
                q.push(vector<long long>{0, timer + meetings[i][1] - meetings[i][0]});
                room[0]++;
                empty[0] = false;
                empty_room = 1;
            } else {
                while (!q.empty() && q.top()[1] <= meetings[i][0]) {
                    empty[q.top()[0]] = true;
                    empty_room = min(empty_room,  q.top()[0]);
                    q.pop();
                }
                if (timer < meetings[i][0]) timer = meetings[i][0];
                q.push(vector<long long>{empty_room, timer + meetings[i][1] - meetings[i][0]});
                room[empty_room]++;
                empty[empty_room] = false;
                while (!empty[empty_room] && empty_room < n) {
                    empty_room++;
                }
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
        int ans_cnt = -1;
        int ans_id = -1;
        for (int i = 0; i < n; i++) {
            if (room[i] > ans_cnt) {
                ans_cnt = room[i];
                ans_id = i;
            }
        }
        return ans_id;
    }
};
