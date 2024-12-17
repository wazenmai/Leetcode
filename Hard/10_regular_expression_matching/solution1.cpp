/**
 * Title:  Regular Expression Matching (Leetcode Hard 10)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, December, 2024
 * Method: Recursion. Deal with two case, one is the next char is '*', then either zero_match or check whether current char match. The other is the next char is not '*'.
 * Result: Time complexity O((T+P)2^(T+P/2)). Space complexity O((T+P)2^(T+P/2)). T = s.length(), P = p.length().
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool first_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if (p.length() >= 2 && p[1] == '*') {
            bool zero_match = isMatch(s, p.substr(2));
            if (first_match) {
                return zero_match || isMatch(s.substr(1), p);
            } else {
                return zero_match;
            }
        }
        return first_match && isMatch(s.substr(1), p.substr(1));
    }
};


// Time complexity
// - In worst case, a call to match(s[i:], pattern[2j:]) will be made C^(i + j)_j times, then string s[n - i] and p[m - 2j] will be made.
// - Then the complexity has order sum^T_{i=0} sum^P/2_{j=0}C^(i+j)_{j=0}O(T+P - i - 2j) -> O((T+P)2^(T+P/2))
// Space complexity
// - For every call to match, if memory is not freed, this will take total O((T+P)2^(T+P/2)) space, even though there are only O(T^2 + P^2) unique suffixes of P and T that are actually required.
