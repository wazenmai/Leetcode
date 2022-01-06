/**
 * Title:  Palindrome Partitioning (Leetcode Medium 131)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   6, Jan, 2022
 * Method: (Improvement) Pass cut point instead of erase string
 */

class Solution {
private:
    vector<vector<string>> pp;
public:
    vector<vector<string>> partition(string s) {
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
            string sub = s.substr(cut, i-cut+1);
            if (!palindrome(sub))
                continue;
            string temp = s;
            ancestor.emplace_back(sub);
            printPartition(s, ancestor, i+1);
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

