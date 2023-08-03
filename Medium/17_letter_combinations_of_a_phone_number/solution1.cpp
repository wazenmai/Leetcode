/**
 * Title:  Letter Combinations of A Phone Number (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, August, 2023
 * Analysis: Time Complexity O(4^n). Sapce Complexity O(n)
 */

class Solution {
private:
    vector<string> ans;
    int n;
public:
    void combine(unordered_map<char, string>& d, string digits, string comb, int pos) {
        if (pos == n) {
            ans.emplace_back(comb);
            return;
        }
        for (char c: d[digits[pos]]) {
            comb += c;
            combine(d, digits, comb, pos + 1);
            comb.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return ans;
        unordered_map<char, string> d;
        d['2'] = "abc";
        d['3'] = "def";
        d['4'] = "ghi";
        d['5'] = "jkl";
        d['6'] = "mno";
        d['7'] = "pqrs";
        d['8'] = "tuv";
        d['9'] = "wxyz";
        n = digits.length();
        combine(d, digits, "", 0);
        return ans;
    }
};
