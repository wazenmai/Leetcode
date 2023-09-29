/**
 * Title:  Decoded String At Index (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, September, 2023
 * Method: Use stack to obtain the length.
 */

class Solution {
public:
    string decodeAtIndex(string& s, int k) {
        stack<long long> lengths; // store the lengths of characters in decoded string

        // Step 1. Calculate lengths for each character in the encoded string
        lengths.push(0); // start with 0 length
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                long long temp = lengths.top() * (s[i] - '0');
                lengths.push(temp);
            } else {
                long long temp = lengths.top() + 1;
                lengths.push(temp);
            }
        }

        // Step 2. Traverse the character lengths to decode and find the kth character
        int ln = lengths.size();
        while (!lengths.empty()) {
            k %= lengths.top();
            ln--;
            if (k == 0 && s[ln - 1] >= 'a' && s[ln - 1] <= 'z') {
                return string(1, s[ln - 1]);
            }

            // move to the previous character length
            lengths.pop();
        }
        return "";
    }
};
