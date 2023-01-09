/**
 * Title: Max Points on A Line (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, Janurary, 2023
 */

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        map<pair<int, int>, int> m;
        for(int i = 0; i < n; i++) {
            // cout << "[" << points[0][0] << ", " << points[0][1] << "]: \n";
            for (int j = i + 1; j < n; j++) {
                int x_diff = points[i][0] - points[j][0];
                int y_diff = points[i][1] - points[j][1];
                if (x_diff < 0) {
                    x_diff = 0 - x_diff;
                    y_diff = 0 - y_diff;
                }
                int num = gcd(x_diff, (y_diff < 0) ? 0 - y_diff : y_diff);
                x_diff /= num;
                y_diff /= num;
                if (x_diff == 0 && y_diff < 0)
                    y_diff = 0 - y_diff;
                auto p = make_pair(x_diff, y_diff);
                // cout << "  (" << p.first << ", " << p.second << "): ";
                if (m.find(p) == m.end()) {
                    m[p] = 2;
                    // cout << "2\n";
                    ans = max(ans, m[p]);
                } else {
                    m[p] += 1;
                    ans = max(ans, m[p]);
                    // cout << m[p] << "\n";
                }
            }
            m.clear();
        }
        return ans;
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } 
        return gcd(b, a%b);
    }
};
