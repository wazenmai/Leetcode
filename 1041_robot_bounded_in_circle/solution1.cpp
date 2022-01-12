/**
 * Title:  Robot Bounded in Circle (Leetcode Medium 1041)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Jan, 2022
 * Result: Accepted, 0ms, faster than 100% of submission
 */

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int round = 4;
        int x = 0, y = 0, direction = 0;
        // direction: 0 for up, 1 for left, 2 for down, 3 for right
        
        while (round--) {
            for (auto& c: instructions) {
                if (c == 'L') {
                    direction = (direction + 1) % 4;
                } else if (c == 'R') {
                    direction = (direction + 3) % 4;
                } else {
                    if (direction == 0)
                        y += 1;
                    else if (direction == 1)
                        x -= 1;
                    else if (direction == 2)
                        y -= 1;
                    else
                        x += 1;
                }
            }
            // cout << "(" << x << ", " << y << ") " << direction << "\n";
        }
        if (x == 0 && y == 0)
            return true;
        return false;
    }
};
