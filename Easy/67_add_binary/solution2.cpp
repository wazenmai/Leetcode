/**
 * Title:  Sum of Root to Leaf Binary Numbers (Leetcode Easy 1022)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Jan, 2022
 * Method: carry = (a&b)|(a&c)|(c&b)
 * Result: Accepted, 0ms, faster than 100% of submission
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.length() - 1;
        int b_len = b.length() - 1;
        int carry = 0;
        string rev = "";
        
        while (a_len >= 0 || b_len >= 0) {
            int a_val = (a_len < 0) ? 0 : a[a_len] - '0';
            int b_val = (b_len < 0) ? 0 : b[b_len] - '0';
            int add = a_val ^ b_val ^ carry;
            rev = rev + to_string(add);
            carry = (a_val & b_val) | (a_val & carry) | (b_val & carry);
            --a_len;
            --b_len;
        }
        if (carry)
            rev = rev + "1";
        reverse(rev.begin(), rev.end());
        return rev;
    }
};
