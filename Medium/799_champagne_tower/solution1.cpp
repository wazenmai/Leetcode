/**
 * Title:  Champagne Tower (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, Mar, 2022
 * Method: DP, state = the total champagne that passes through the glass(i, j)
 */

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> state(100, vector<double>(100, 0));
        state[0][0] = poured;
        
        for (int i = 1; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    state[i][j] = state[i-1][j] >= 1 ? (state[i-1][j] - 1) / 2 : 0;
                } else if (j == i) {
                    state[i][j] = state[i-1][j-1] >= 1 ? (state[i-1][j-1] - 1) / 2 : 0;
                } else {
                    if (state[i-1][j-1] >= 1 && state[i-1][j] >= 1)
                        state[i][j] = (state[i-1][j-1] - 1) / 2 + (state[i-1][j] - 1) / 2;
                    else if (state[i-1][j-1] >= 1)
                        state[i][j] = (state[i-1][j-1] - 1) / 2;
                    else if (state[i-1][j] >= 1)
                        state[i][j] = (state[i-1][j] - 1) / 2;
                    else
                        state[i][j] = 0;
                }
                
                if (i == query_row && j == query_glass)
                    break;
            }
        }
        
        return state[query_row][query_glass] > 1 ? 1 : state[query_row][query_glass];
    }
};

/*
state[i][j] = 流過 glass (i, j) 的總水量
state[0][0] = poured   13

state[1][0] = (state[0][0] - 1) / 2  6
state[1][1] = (state[0][0] - 1) / 2  6

state[2][0] = (state[1][0] - 1) / 2 2.5
state[2][1] = ((state[1][0] - 1) + (state[1][1] - 1)) / 2. 5
state[2][2] = (state[1][1] - 1) / 2 2.5
    
state[3][0] = (state[2][0] - 1) / 2. 5/4
state[3][1] = ((state[2][0] - 1) + (state[2][1] - 1)) / 2  11/4
state[3][2] = ((state[2][1] - 1) + (state[2][2] - 1)) / 2  11/4
state[3][3] = (state[2][2] - 1) / 2. 5/4
    
state[4][0] = (state[3][0] - 1) / 2 1/8
state[4][1] = ((state[3][0] - 1) + (state[3][1] - 1)) / 2  1
state[4][2] = ((state[3][1] - 1) + (state[3][2] - 1)) / 2  7/4
state[4][3] = ((state[3][2] - 1) + (state[3][3] - 1)) / 2  1
state[4][4] = (state[3][3] - 1) / 2. 1/8

state[5][0] = 0
state[5][1] = 0
state[5][2] = 3/8
state[5][3] = 3/8
*/
