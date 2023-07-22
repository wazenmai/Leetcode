/**
 * Title:  Knight Probability in Chessboard (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, July, 2023
 * Method: DP[i][j] = probability of the knight be on the pos (i,j). Time complexity: O(kn^2), Space complexity: O(n^2)
 */

class Solution {
private:
    int dirx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int diry[8] = {2, 1, -1, -2, -2, -1, 1, 2};
public:
    void printVec(vector<vector<double>>& v) {
        for (auto e: v) {
            for (double d: e) {
                cout << d << " ";
            }
            cout << "\n";
        }
        cout << "-------\n";
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1; // first pos

        for (int i = 0; i < k; i++) {
            vector<vector<double>> ndp(n, vector<double>(n, 0));
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int j = 0; j < 8; j++) {
                        int nx = x + dirx[j];
                        int ny = y + diry[j];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        ndp[x][y] += dp[nx][ny] / 8.0;
                    }
                }
            }
            printVec(ndp);
            dp = ndp;
        }
        double p = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p += dp[i][j];
            }
        }
        return p;
    }
};

/*
0 0 0 0 0
0 0 0 0 0 
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0 

0 1 2 1 0 | 0 0 2 0 0 
1 2 0 2 1 | 0 2 0 2 0
2 0 2 0 2 | 2 0 8 0 2
1 2 0 2 1 | 0 2 0 2 0
0 1 2 1 0 | 0 0 2 0 0

0 3 0 3 0
3 0 4 0 3 
0 4 0 4 0
3 0 4 0 3
0 3 0 3 0 
*/

/*
step 1: 8 (1)
    - 1/8 * 1/2 + 1/8 * 1/2 + 1/8 = 1/4
    - 1/8 * 1/2 + 1/8 * 1/2 + 1/8
    - 1/8 * 1/2 + 1/8 * 1/2 + 1/8
    - 
    - 
    - 
    - 
step 2: every move has 3/8 possibility to survive
step 3: circle has 1, 7 place has 1/2 possibility to survive

dp[i][j] = probability of the knight be on the pos (i,j)
init: dp = 1
move = 1 ~ k
    - new dp to store updated prob
    - iterate through each cell (r, c) in orig. dp
        - new dp = orig dp / 8
*/
