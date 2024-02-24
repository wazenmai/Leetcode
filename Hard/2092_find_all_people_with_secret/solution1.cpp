/**
 * Title:  Find All People With Secret (Leetcode Hard 2092)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, February, 2024
 * Method: We need to connect all people in meetings at the same time - UnionFind. When the time changes, we need to check if there is any secret that can be passed to other people. 
  *        Use a map to record the group of people and the secret in the group. If the group has a secret, pass the secret to other people in the group. We can use a vector to record the secret people and return the result.
 * Result: TLE. Time complexity O(mlogm (sort) + 2mlogn (union) + m * 2nlogn * n (construct map)), m = # of meetings, n = # of people. Space Complexity O(n).
 */

class UnionSet {
public:
    vector<int> rank;
    vector<int> parent;
    UnionSet(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int check(int x) {
        if (parent[x] == x) return x;
        return check(parent[x]);
    }
    void union_two(int x, int y) {
        int px = check(x);
        int py = check(y);
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
    void reset(int n) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
};

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    void print(vector<vector<int>>& v) {
        for (auto& meet: v) {
            cout << "(" << meet[0] << "," << meet[1] << "," << meet[2] << ") ";
        }
        cout << "\n";
    }
    void print(vector<int>& v) {
        for (auto& p: v) {
            cout << p << " ";
        }
        cout << "\n";
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), compare);
        int time = meetings[0][2];
        int mn = meetings.size();
        vector<bool> secret(n, false);
        secret[0] = secret[firstPerson] = true;
        vector<int> ans{0, firstPerson};
        UnionSet us(n);
        bool flag = secret[meetings[0][0]] || secret[meetings[0][1]];
        us.union_two(meetings[0][0], meetings[0][1]);
        for (int i = 1; i < mn; i++) {
            // cout << "meeting " << i << ": (" << meetings[i][0] << "," << meetings[i][1] << "," << meetings[i][2] << "), flag: " << flag << "\n";
            if (meetings[i][2] != time && flag) {
                // Grouping
                unordered_map<int, vector<int>> m;
                unordered_map<int, int> secret_map; // record the group with secret
                for (int j = 0; j < n; j++) {
                    m[us.parent[j]].emplace_back(j);
                    if (secret[j]) {
                        secret_map[us.parent[j]] = 1;
                    }
                }
                // Pass secret
                for (auto it = m.begin(); it != m.end(); it++) {
                    if (secret_map[it->first] == 1) { // this group has secret
                        for (int& p: it->second) {
                            if (!secret[p]) {
                                ans.emplace_back(p);
                                secret[p] = true;
                                if (ans.size() == n) return ans;
                            }
                        }
                    }
                }
                // Reset UnionSet and update time
                us.reset(n);
                time = meetings[i][2];
                flag = false;
                // cout << "Pass secret: ";
                // print(ans);
            } else if (meetings[i][2] != time){
                us.reset(n);
                time = meetings[i][2];
            }
            us.union_two(meetings[i][0], meetings[i][1]);
            flag = flag || secret[meetings[i][0]] || secret[meetings[i][1]];
        }
        if (flag) {
            unordered_map<int, vector<int>> m;
            unordered_map<int, int> secret_map; // record the group with secret
            for (int j = 0; j < n; j++) {
                m[us.parent[j]].emplace_back(j);
                if (secret[j]) {
                    secret_map[us.parent[j]] = 1;
                    cout << us.parent[j] << " ";
                }
            }
            // Pass secret
            for (auto it = m.begin(); it != m.end(); it++) {
                if (secret_map[it->first] == 1) { // this group has secret
                    for (int& p: it->second) {
                        if (!secret[p]) {
                            ans.emplace_back(p);
                            secret[p] = true;
                            if (ans.size() == n) return ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// n people: 0 ~ n - 1
// Initial: secret - 0, 1
// [1,2,5] [2,3,8] [1,5,10]

// [1,2,1] [2,3,1] [3,4,1] [4,5,1]

// 0 1 2 3 4 5
// 0 1 1 1 1 1
// 0 1 0 0 0 0