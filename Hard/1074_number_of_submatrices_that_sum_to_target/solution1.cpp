/**
 * Title:  Number of Submatrices That Sum to Target (Leetcode Hard 1074)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Janurary, 2024
 * Method: Prefix Sum. p = prefix sum of each row. s = prefix sum of whole matrix.
    *         (i, j) -> (x, y) = (p[x][y] - p[x][j - 1]) + (p[x - 1][y] - p[x - 1][j - 1]) + ... + (p[i][y] - p[i][j - 1])
    *         (i, j) -> (x, y) = s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1]
    *         since s is bounded by (i, j), so it start from row i, we can use a map to store appeared prefix sum and check s[y] - target
 * Result: Time complexity O(n^2m), space complexity O(nm)
 */

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // Calculate prefix sum
        vector<vector<int>> p(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            p[i][0] = matrix[i][0];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                p[i][j] = p[i][j - 1] + matrix[i][j];
            }
        }
        // Find submatrix sum that fit target
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> s(m);
            for (int x = i; x < n; x++) {
                for (int j = 0; j < m; j++) {
                    s[j] += p[x][j];
                }

                unordered_map<int, int> box;
                box[0] = 1;
                for (int y = 0; y < m; y++) {
                    ans += box[s[y] - target];
                    box[s[y]]++;
                }
            }
        }
        return ans;
    }
};

// prefix sum of each row: p
// 0 1 0
// 1 1 1
// 0 1 0

// 0 1 1 p[0]
// 1 2 3 p[1]
// 0 1 1 p[2]

// 0 1 1 s
// 1 3 4 s
// 1 4 5 s

// 指定左上角的點 (i, j) 跟右下角的點 (x, y)
// (2, 3) ~ (2, 10): p[2][10] - p[2][2]
// (3, 3) ~ (3, 10): p[3][10] - p[3][2]
// (2, 3) ~ (3, 10): (p[3][10] - p[3][2]) + (p[2][10] - p[2][2])

// And we have s, the prefix sum of whole matrix.  (i, j) -> (x, y)
// s = p[i] (an array) + p[i + 1] (an array) + ... p[x] (current array)

// (0, 3) ~ (2, 10): s[2][10] - s[0][2]
// (2, 3) ~ (3, 10): s[3][10] - s[2][3]

// s[3][10] - target = ? (appear before?) -> use set?

// 1 -1
// -1 1

// 0 1 0
// 0 -1 0
