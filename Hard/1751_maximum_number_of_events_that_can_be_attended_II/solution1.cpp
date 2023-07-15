/**
 * Title:  Maximum Number of Events That Can Be Attended II (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Janurary, 2023
 * Method: Top Down DFS + DP + Binary Search. Time Complexity: O(NKlogN), Space Complexity: O(NK)
 */

const static auto _ = []() {
    cin.tie(nullptr)->sync_with_stdio(false);
    return nullptr;
}();

class Solution {
private:
    void printVector(vector<int>& v) {
        for (int e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
public:
    static bool mycompare(vector<int>& a, vector<int>& b) {
        // small start date
        return a[0] < b[0];
    }

    int dfs(const vector<vector<int>>& events, int k, int i, int j, vector<vector<int>>& dp, const vector<int>& bs) {
        // At i-th event, already choosed j events
        if (j == k || i == (int)events.size()) // already choosed k events or at last event
            return 0;
        const auto& e = events[i];
        int& d = dp[i][j]; // ref
        if (d != 0)
            return d;
        d = max(dfs(events, k, bs[i], j + 1, dp, bs) + e[2], dfs(events, k, i + 1, j, dp, bs));
        return d;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), mycompare);
        int numEvents = (int)events.size();
        vector<vector<int>> dp(numEvents, vector<int>(k, 0)); // ith event, attended event
        vector<int> bs(numEvents, 0);
        // use bs to find next date
        for (int i = 0; i < numEvents; i++) {
            int l = i + 1;
            int r = numEvents;
            while (l < r) {
                int mid = (l + r) / 2;
                if (events[mid][0] > events[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }
            bs[i] = r;
        }
        return dfs(events, k, 0, 0, dp, bs);
    }
};

// dfs(i, j) {
//     1. choose i
//       dfs(ii, j + 1) + cost[i]
//     2. not choose i
//       dfs(i + 1, j)
// }

// O(NKlogN)

// 1 2
// 2 3
// 2 4
// 2 5

