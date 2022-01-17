/**
 * Title:  Maximize Distance to Closest Person (Leetcode Medium 849)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Jan, 2022
 * Method: Calculate the number of continuous 0
 */

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        int start_index = -1;
        int end_index = 0;
        int space = 0;
        int max_space = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (seats[i]) {
                if (start_index == -1) {
                    if (((space - 1) / 2 + 1) > max_space) {
                        end_index = i;
                        start_index = index;
                        max_space = space;
                    }
                } else {
                    if (space > max_space) {
                        end_index = i;
                        start_index = index;
                        max_space = space;
                    }
                }
                space = 0;
                index = i;
            } else {
                space++;
            }
        }
        
        if (space >= max_space) {
            start_index = index;
            end_index = n;
            max_space = space;
        }
        // cout << start_index << " " << end_index << " " << max_space;
        if (start_index == -1) {
            return max_space;
        }
        if (space > (max_space - 1) / 2 + 1) {
            return space;
        }
        return (max_space - 1) / 2 + 1;
    }
};
