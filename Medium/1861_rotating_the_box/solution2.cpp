/**
 * Title:  Rotating the Box (Leetcode Medium 1861)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, November, 2024
 * Method: Combine two steps into one.
 * Result: Time complexity O(n * m), Space complexity O(n * m).
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size(), col = box[0].size();
        vector<vector<char>> rotate(col, vector<char>(row, '.'));
        for (int i = 0; i < row; i++) {
            int bottom = col - 1;
            for (int j = col - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    rotate[j][row - i - 1] = '*';
                    bottom = j - 1;
                } else if (box[i][j] == '#') {
                    rotate[bottom][row - i - 1] = '#';
                    bottom--;
                }
            }
        }
        return rotate;
    }
};