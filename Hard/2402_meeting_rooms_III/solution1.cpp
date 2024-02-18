/**
 * Title:  Meeting Rooms III (Leetcode Hard 2402)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, February, 2024
 * Method: First sort the meeting time with start tiem. Then use priority queue to matain ungoing meeting with room and end time. Use long long in case of overflow.
    * Whenever all rooms are occupied, pop the meeting with the earliest end time and update the timer to this end time.
 * Result: Time complexity O(mlogm + mlogn), space complexity O(n). Runtime 403 ms, Memory 113.88 MB.
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
    void print(vector<vector<int>>& v) {
        for (auto& e: v) {
            cout << "(" << e[0] << "," << e[1] << ") ";
        }
        cout << "\n";
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        // print(meetings);
        priority_queue<vector<long long>, vector<vector<long long>>, Compare> q;
        long long empty_room = 0;
        vector<int> room(n, 0);
        vector<bool> empty(n, true);
        int m = meetings.size();
        // cout << "# of meetings: " << m << "\n";
        long long timer = 0;
        for (int i = 0; i < m; i++) {
            // cout << "time: " << timer << "\n";
            if (q.size() == 0) { // no meeting now
                if (timer < meetings[i][0])
                    timer = meetings[i][0];
                q.push(vector<long long>{0, timer + meetings[i][1] - meetings[i][0]});
                room[0]++;
                empty[0] = false;
                empty_room = 1;
                // cout << "meeting " << i << " in room 0\n";
            } else {
                while (!q.empty() && q.top()[1] <= meetings[i][0]) {
                    empty[q.top()[0]] = true;
                    cout << "room " << q.top()[0] << " empty\n";
                    empty_room = min(empty_room,  q.top()[0]);
                    q.pop();
                }
                if (timer < meetings[i][0])
                    timer = meetings[i][0];
                q.push(vector<long long>{empty_room, timer + meetings[i][1] - meetings[i][0]});
                // cout << "meeting " << i << " in room " << empty_room << "\n";
                room[empty_room]++;
                empty[empty_room] = false;
                while (!empty[empty_room] && empty_room < n) {
                    empty_room++;
                }
            }
            if (empty_room == n) {
                timer = q.top()[1];
                // cout << "time: " << timer << "\n";
                while (!q.empty() && q.top()[1] <= timer) {
                    empty[q.top()[0]] = true;
                    // cout << "room " << q.top()[0] << " empty\n";
                    empty_room = min(empty_room, q.top()[0]);
                    q.pop();
                }
            }
        }
        int ans_cnt = -1;
        int ans_id = -1;
        for (int i = 0; i < n; i++) {
            // cout << "(" << i << "," << room[i] << ") ";
            if (room[i] > ans_cnt) {
                ans_cnt = room[i];
                ans_id = i;
            }
        }
        // cout << "ans: " << ans_id << "\n";
        return ans_id;
    }
};
