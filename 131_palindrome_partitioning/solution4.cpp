/**
 * Title:  Palindrome Partitioning (Leetcode Medium 131)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   6, Jan, 2022
 * Method: (Improvement) First buttom-up calculates pd to reduce running time
 */

class Solution {
private:
    vector<vector<string>> pp;
    bool pd[17][17];
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
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
            string sub = s.substr(cut, i-cut+1);
            ancestor.emplace_back(sub);
            printPartition(s, ancestor, i+1);
            ancestor.pop_back();
        }
    }
};


