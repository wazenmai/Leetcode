/**
 * Title:  Flood Fill (Leetcode Easy 733)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, Mar, 2021
 */

// bfs, failed
class Solution {
private:
    typedef struct {
        int r, c, n;
        int d; // 1 2 3 4 down up left right, 0 no
    } node;
    node MakeNode(int r, int c, int n, int d) {
        node res = {.r=r, .c=c, .n=n, .d=d};
        return res;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        queue<node> q;
        node temp;
        q.push(MakeNode(sr, sc, image[sr][sc], 0));

        while (!q.empty()) {
            temp = q.front();
            for (int i = 0; i < 4; i++) {
                int new_x = temp.c + dx[i];
                int new_y = temp.r + dy[i];
                if (new_x < 0 || new_x >= image[0].size())
                    continue;
                if (new_y < 0 || new_y >= image.size())
                    continue;
                // direction
                if (temp.d == i)
                    continue;
                int new_d = (i % 2) ? (i + 1) : (i - 1);
                if (image[new_y][new_x] == temp.n)
                    q.push(MakeNode(new_y, new_x, temp.n, new_d));
            }
            image[temp.r][temp.c] = newColor;
            q.pop();
        }
        return image;
    }
};

/*
111  222
110  220
101  201
*/
