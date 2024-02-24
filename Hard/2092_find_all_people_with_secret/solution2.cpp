/**
 * Title:  Find All People With Secret (Leetcode Hard 2092)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, February, 2024
 * Method: Instead of resetting UnionSet every time changes, we use a set to record the people in the meeting at the same time and matain UnionSet across all the meetings.
  *        Whenever time changes, we iterate the set to check whether this person is connected with 0. If not, reset the person.
 * Result: Pass. Time Complexity O(mlogm + mlogn (UnionSet) + mlogn (set) + alpha * nlogn (check connected in set)), m = # of meetings, n = # of people, alpha = # of unique time in meeting. Space Complexity O(n).
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
    int find(int x) {
        if (parent[x] == x) return x;
        return find(parent[x]);
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
        int m = meetings.size();
        UnionSet uf(n);
        uf.connect(0, firstPerson);
        unordered_set<int> us; // people in meeting at same time
        for (int i = 0; i < m; i++) {
            // cout << i << ":(" << meetings[i][0] << "," << meetings[i][1] << "," << meetings[i][2] << ") ";
            us.clear();
            int time = meetings[i][2];
            for (int j = i; j < m && meetings[j][2] == time; j++) {
                uf.connect(meetings[j][0], meetings[j][1]);
                us.insert(meetings[j][0]);
                us.insert(meetings[j][1]);
                i = j;
            }
            // cout << "to " << i << "\n";
            for (auto it = us.begin(); it != us.end(); it++) {
                if (!uf.connected(0, *it)) {
                    uf.reset(*it);
                    // cout << "reset " << *it << "\n";
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (uf.connected(0, i)) {
                ans.emplace_back(i);
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