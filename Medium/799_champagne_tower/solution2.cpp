/**
 * Title:  Champagne Tower (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, Mar, 2022
 * Method: Retidy the code.
 */

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> state(query_row + 1, vector<double>(query_row + 1, 0));
        state[0][0] = poured;
        
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (state[i][j] > 1) {
                    state[i + 1][j] += (state[i][j] - 1) / 2;
                    state[i + 1][j + 1] += (state[i][j] - 1) / 2;
                }
            }
        }

        return state[query_row][query_glass] > 1 ? 1 : state[query_row][query_glass];
    }
};
