/**
 * Title:  Find the Closest Palindrome (Leetcode Hard 564)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, August, 2024
 * Method: There are 5 possible candidates: (1) copy the first half and mirror it; (2) copy the first half + 1 and mirror it; (3) copy the first half - 1 and mirror it; (4) 999...; (5) 1000...1.
 *         Compare the difference between the candidates and the original number, and return the smallest one.
 * Result: Time complexity O(n), Space complexity O(n), where n = length of the input string.
 */

class Solution {
public:
    long half(long left, bool even) {
        long res = left;
        if (!even) left /= 10;
        while (left > 0) {
            res = res * 10 + left % 10;
            left /= 10;
        }
        return res;
    }
    string nearestPalindromic(string n) {
        int l = n.length();
        int i = (l - 1) / 2;
        long firstHalf = stol(n.substr(0, i + 1));
        vector<long> res;
        // 1. mirror the first half
        res.emplace_back(half(firstHalf, !(l & 1)));
        // 2. mirror the first half + 1
        res.emplace_back(half(firstHalf + 1, !(l & 1)));
        // 3. mirror the first half - 1
        res.emplace_back(half(firstHalf - 1, !(l & 1)));
        // 4. 999...
        res.emplace_back((long)pow(10, l - 1) - 1);
        // 5. 1000...1
        res.emplace_back((long)pow(10, l) + 1);

        long diff = LONG_MAX, ans = 0, nl = stol(n);
        for (auto& candidate: res) {
            if (candidate == nl) continue;
            if (abs(candidate - nl) < diff) {
                diff = abs(candidate - nl);
                ans = candidate;
            } else if (abs(candidate - nl) == diff) {
                ans = min(candidate, ans);
            }
        }
        return to_string(ans);
    }
};
// 1234 -> 1221
// 999 -> 989
// 1000 -> 999
// 12932 -> 12921
// 99800 -> 99799
// 12120 -> 12121
// 123 -> 121
// 1 -> 0
// 139 -> 141
// 

// 87654321 , 4 8
// 123456789 9 / 2, 5
