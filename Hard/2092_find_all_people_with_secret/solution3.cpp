/**
 * Title:  Find All People With Secret (Leetcode Hard 2092)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, February, 2024
 * Method: Further optimized and add compiler flags. Only maintain one UnionSet across meetings and whenever time changes, check whether people in the same time meeting connect with zero.
 * Result: Pass. Time Complexity O(mlogm + m * 3logn + nlogn) = O(mlogm + (m + n)logn). Space Complexity O(n). Beats 99% of users with C++. (322ms). Beats 95% of users with C++ (136.8 MB).
 */

static const int _ = []() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0; 
}();

class UnionSet {
private:
    vector<int> rank;
    vector<int> parent;
public:
    UnionSet(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    void connect(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
    void reset(int x) {
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), compare);
        UnionSet uf(n);
        int m = meetings.size();
        uf.connect(0, firstPerson);
        for (int i = 0; i < m; i++) {
            int time = meetings[i][2];
            uf.connect(meetings[i][0], meetings[i][1]);
            if (i == m - 1 || meetings[i][2] != meetings[i + 1][2]) {
                int j = i;
                while (j >= 0 && meetings[j][2] == time) {
                    if (!uf.connected(0, meetings[j][0])) uf.reset(meetings[j][0]);
                    if (!uf.connected(0, meetings[j][1])) uf.reset(meetings[j][1]);
                    j--;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (uf.connected(0, i)) ans.emplace_back(i);
        }
        return ans;
    }
};
