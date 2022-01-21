/**
 * Title:  Gas Station (Leetcode Medium 134)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, Jan, 2022
 * Method: Find sum of (gas[i] - cost[i]), the start index of most positive number is answer
 * Result: Wrong Answer
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        vector<int> tank;
        int start_idx, end_idx, maximum;
        int temp_s, temp_e, temp;
        int sum = 0;
        start_idx = end_idx = maximum = -1;
        temp_s = temp_e = temp = 0;
        
        for (int i = 0; i < n; i++) {
            tank.emplace_back(gas[i] - cost[i]);
            sum += gas[i] - cost[i];
            if (gas[i] - cost[i] >= 0) {
                if (temp == 0) {
                    temp_s = i;
                }
                temp += gas[i] - cost[i];
                temp_e = i;
            } else {
                if (temp > 0 && temp > maximum) {
                    maximum = temp;
                    start_idx = temp_s;
                    end_idx = temp_e;
                }
                temp = 0;
                temp_s = -1;
                temp_e = -1;
            }
            cout << temp_s << " " << temp_e << " " << temp << "\n";
        }
        if (temp > maximum) {
            maximum = temp;
            start_idx = temp_s;
            end_idx = temp_e;
        }
        if (sum < 0)
            return -1;
        return start_idx;
    }
};
// -2 -2 -2 3 3 3 3 -2 -4 -5 4 1
// -2 -4 -6 -3 0 3 6 4  0 -5 -1 0

// 1 -2 2 -1 0 -1 -1 -1 3 0
// 最大正區間

// -1 3 -4 2

// [5,8,2,8]
// [6,5,6,6]
