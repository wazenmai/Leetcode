/**
 * Title:  Flood Fill (Leetcode Easy 733)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, Mar, 2021
 */

// bfs, failed
class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int source, int nc) {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || image[r][c] != source)
            return;
        image[r][c] = nc;
        dfs(image, r + 1, c, source, nc); // up
        dfs(image, r - 1, c, source, nc); // down
        dfs(image, r, c + 1, source, nc); // right
        dfs(image, r, c - 1, source, nc); // left
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

/*
111  222
110  220
101  201
*/
