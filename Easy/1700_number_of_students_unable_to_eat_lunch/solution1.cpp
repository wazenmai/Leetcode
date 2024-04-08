/**
 * Title:  Number of Students Unable to Eat Lunch (Leetcode Easy 1700)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, April, 2024
 * Method: Use a queue to simulate the process. If the first student in the queue can eat the sandwich, pop it and move to the next student. If the first student in the queue cannot eat the sandwich, push it to the end of the queue and move to the next student. If the queue is empty, return 0. If the queue is not empty and the first student in the queue cannot eat the sandwich, return the size of the queue.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (auto& s: students) {
            q.push(s);
        }
        int j = 0;
        int rep = 0;
        int n = sandwiches.size();
        while (!q.empty() && j < n) {
            auto s = q.front();
            // cout << s << ", " << j << ": " << sandwiches[j] << "\n";
            q.pop();
            if (sandwiches[j] == s) {
                j++;
                rep = 0;
            } else {
                q.push(s);
                rep++;
                if (rep == q.size()) {
                    return q.size();
                }
            }
        }
        return 0;
    }
};
