/**
 * Title:  Find the Closest Palindrome (Leetcode Hard 564)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, August, 2024
 * Method: Use binary search to find the closest palindrome that is smaller than and larger than the input number.
 * Result: Time complexity O(logm), Space complexity O(1), where m = input number.
 */

class Solution {
public:
    // convert num to palindrome keeping first half constant
    long long convert(long long& num) {
        string s = to_string(num);
        int n = s.length();
        int l = (n - 1) / 2, r = n / 2;
        while (l >= 0) s[r++] = s[l--];
        return stoll(s);
    }
    long long small_bs(long long& num) {
        long long l = 0, r = num - 1;
        long long ans = 0;
        while (l <= r) {
            long long mid = (r - l) / 2 + l;
            long long pa = convert(mid);
            if (pa < num) {
                ans = pa;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
    long long big_bs(long long& num) {
        long long l = num + 1, r = 1e18;
        long long ans = 0;
        while (l <= r) {
            long long mid = (r - l) / 2 + l;
            long long pa = convert(mid);
            if (pa > num) {
                ans = pa;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        long long pre = small_bs(num);
        long long nxt = big_bs(num);
        if (num - pre <= nxt - num) return to_string(pre);
        return to_string(nxt);
    }
};

// [1, 5]