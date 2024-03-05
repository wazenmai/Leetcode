/**
 * Title:  Minimum Length of String After Deleting Similar Ends (Leetcode Medium 1750)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, March, 2024
 * Method: Two pointers. If the left and right characters are the same, move the left pointer to the next different character and move the right pointer to the previous different character. If the left and right characters are different, break the loop. Return the length of the substring between the left and right pointers.
 * Result: Time complexity O(n), Space complexity O(1).
 */

class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            // cout << left << ": " << s[left] << ", " << right << ": " << s[right] << "\n";
            if (s[left] == s[right]) {
                int next_left = left;
                while (s[next_left] == s[left] && next_left < right) {
                    next_left++;
                }
                int next_right = right;
                while (s[next_right] == s[right] && next_right > left) {
                    next_right--;
                }
                left = next_left;
                right = next_right;
            } else {
                break;
            }
        }
        return (right < left) ? 0 : right - left + 1;
    }
};
