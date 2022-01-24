/**
 * Title:  Palindrome Partitioning (Leetcode Medium 131)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   6, Jan, 2022
 * Method: (Improvement) vector<vector<bool>> is much smaller than bool[][]
 */

class Solution {
private:
    vector<vector<string>> pp;
    vector<vector<bool>> pd;
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        for (int i = 0; i < n+1; i++)
            pd.emplace_back(vector<bool>(n, false));
        
        for (int i = n-1; i >= 0; i--) {
            pd[i][i] = 1;
            pd[i+1][i] = 1;
            for (int j = i+1; j < n; j++)
                pd[i][j] = (s[i] == s[j] && pd[i+1][j-1]);
        }
        
        vector<string> vs;
        printPartition(s, vs, 0);
        return pp;
    }
    
    void printPartition(string& s, vector<string>& ancestor, int cut) {
        int n = s.length();
        if (cut == n) {
            pp.emplace_back(ancestor);
            return;
        }
        for (int i = cut; i < n; i++) {
            if (!pd[cut][i])
                continue;
            ancestor.emplace_back(s.substr(cut, i-cut+1));
            printPartition(s, ancestor, i+1);
            ancestor.pop_back();
        }
    }
};
