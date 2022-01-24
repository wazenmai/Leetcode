/**
 * Title:  Sum of Root to Leaf Binary Numbers (Leetcode Easy 1022)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Jan, 2022
 * Result: Accepted, 4ms
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.length() - 1;
        int b_len = b.length() - 1;
        int carry = 0;
        string rev = "";
        // int idx = 1;
        
        while (a_len >= 0 || b_len >= 0) {
            int a_val = (a_len < 0) ? 0 : a[a_len] - '0';
            int b_val = (b_len < 0) ? 0 : b[b_len] - '0';
            // cout << idx << ": (" << a_val << ", " << b_val << ") ";
            // idx++;
            int add = a_val ^ b_val ^ carry;
            rev = rev + to_string(add);
            if ((a_val | b_val | carry) == 0)
                carry = 0;
            else if (a_val & b_val & carry)
                carry = 1;
            else
                carry = (!add);
            // cout << add << " " << carry << "\n";
            --a_len;
            --b_len;
        }
        if (carry)
            rev = rev + "1";
        reverse(rev.begin(), rev.end());
        return rev;
    }
};
