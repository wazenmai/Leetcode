/**
 * Title:  Move Pieces to Obtain a String (Leetcode Medium 2337)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, December, 2024
 * Method: First check whether the order of L, R of start and target are the same. Second, use a queue to record L, R's position in the target, and iterate the start to check whether the criteria meet.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        // Step 1. check whether the order
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;
            if (start[i] == target[j]) {
                i++;
                j++;
            } else {
                break;
            }
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;
        }
        if (i < n || j < n) return false;

        // Step 2. 
        queue<pair<int, char>> q;
        for (i = 0; i < n; i++) {
            if (target[i] != '_') {
                q.push(make_pair(i, target[i]));
            }
        }
        int space = 0; // # of space left in left
        int r = 0; // for right move
        bool flag = true;
        for (i = 0; i < n; i++) {
            if (q.empty()) break;
            auto c = q.front(); // (pos, char)
            // cout << "start[" << i << "]: " << start[i] << ", space=" << space << ", c=(" << c.first << "," << c.second << "), r=" << r << "\n";
            if (start[i] == '_') {
                space++;
                if (c.first == i && c.second == 'R') {
                    if (r == 0) {
                        flag = false;
                        break;
                    } else {
                        r--;
                        space = 0;
                        q.pop();
                    }
                }
            } else if (start[i] == 'L') {
                if (c.second == 'L' && i - space <= c.first && i >= c.first) {
                    q.pop();
                    space = i - c.first;
                } else {
                    flag = false;
                    break;
                }
            } else { // start[i] = 'R'
                if (c.second == 'R' && c.first == i) {
                    if (r == 0) {
                        space = 0;
                        q.pop();
                    } else {
                        q.pop();
                    }
                } else if (c.second == 'L') {
                    flag = false;
                    break;
                } else {
                    if (c.first < i) { // target 'R' is at the left side of start
                        flag = false;
                        break;
                    } else {
                        r++;
                    }
                }
            }
        }
        return flag;
    }
};
