/**
 * Title:  Palindrome Partitioning (Leetcode Medium 131)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   6, Jan, 2022
 * Method: Recursion - backtracking + pass by reference (2 times faster)
 */

class Solution {
private:
    vector<vector<string>> pp;
public:
    vector<vector<string>> partition(string s) {
        vector<string> vs;
        printPartition(s, vs);
        return pp;
    }
    
    void printPartition(string& s, vector<string>& ancestor) {
        int n = s.length();
        if (n == 0) {
            pp.emplace_back(ancestor);
            return;
        }
        if (n == 1) {
            ancestor.emplace_back(s);
            pp.emplace_back(ancestor);
            ancestor.pop_back();
            return;
        }
        for (int i = 0; i < n; i++) {
            string sub = s.substr(0, i+1);
            if (!palindrome(sub))
                continue;
            string temp = s;
            ancestor.emplace_back(sub);
            printPartition(temp.erase(0, i+1), ancestor);
            ancestor.pop_back();
        }
    }
    
    bool palindrome(string& test) {
        int len = test.length();
        for (int j = 0; j < len / 2; j++) {
            if (test[j] != test[len - j -1])
                return false;
        }
        return true;
    }
};
