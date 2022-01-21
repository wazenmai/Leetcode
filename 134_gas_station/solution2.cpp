/**
 * Title:  Gas Station (Leetcode Medium 134)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, Jan, 2022
 * Method: If we choose right start index, it won't make the sum turn to negative
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        int temp = 0;
        int sum = 0;
        int index = 0;
        
        for (int i = 0; i < n; i++) {
            temp += gas[i] - cost[i];
            if (temp < 0) {
                index = i + 1;
                sum += temp;
                temp = 0;
            }
        }
        return (sum + temp) >= 0 ? index : -1;
    }
};
