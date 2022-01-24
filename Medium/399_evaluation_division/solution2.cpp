/**
 * Title:     Evaluation Division (Leetcode Medium 399)
 * Author:    Bronwin Chen <iotbwu0101@gmail.com>
 * Date:      26, Apr, 2021
 * Method:    Union Find
 * Reference: https://github.com/justin0u0/leetcode/blob/master/problems/0399-evaluate-division/solution.cpp
 */

 // Union set

class Helper {
private:
    unordered_map<string, int> table;
    int idx = 1;
public:
    int getID(string &s) {
        return (!table[s]) ? (table[s] = idx++) : table[s];
    }

    bool exist(string &s) {
        return (table[s]) ? true : false;
    }
};

class UnionSet {
private:
    vector<int> us;
    vector<double> val;
public:
    UnionSet(int n) {
        us.resize(n);
        val.resize(n, 1.0);
        for (int i = 0; i < n; i++) {
            us[i] = i; // point at itself
        }
    }

    void MergeSet(int x, int y, double value) {
        int fx = FindSet(x);
        int fy = FindSet(y);
        us[fx] = fy;
        val[fx] = val[y] / val[x] * value;
    }

    int FindSet(int x) {
        if (us[x] == x)
            return x;
        int fx = FindSet(us[x]);
        val[x] *= val[us[x]];
        us[x] = fx;
        return fx;
    }

    double Solve(int x, int y) {
        return (FindSet(x) == FindSet(y)) ? val[x] / val[y] : -1.0;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionSet* u = new UnionSet(50);
        Helper* h = new Helper();
        vector<double> ans;

        int sz = equations.size();
        for (int i = 0; i < sz; i++) {
            u->MergeSet(h->getID(equations[i][0]), h->getID(equations[i][1]), values[i]);
        }

        for (auto& q: queries) {
            if (!h->exist(q[0]) || !h->exist(q[1])) {
                ans.emplace_back(-1.0);
            } else {
                ans.emplace_back(u->Solve(h->getID(q[0]), h->getID(q[1])));
            }
        }
        delete u;
        delete h;
        return ans;
    }
};
