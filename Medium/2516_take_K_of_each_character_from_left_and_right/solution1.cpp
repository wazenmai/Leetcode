/**
 * Title:  Take K of Each Character From Left and Right (Leetcode Medium 2516)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, November, 2024
 * Method: First calculate from the right till meet criteria. Then iterate from left, every time we take an element from left, we can move our right pointer to right (take less on right).
 * Result: Time complexity O(n), space complexity O(1). // n is the length of the string.
 */

class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        vector<int> right(3, 0);
        int n = s.length();
        int j;
        for (j = n - 1; j >= 0; j--) {
            right[s[j] - 'a']++;
            if (right[0] >= k && right[1] >= k && right[2] >= k) break;
        }
        if (right[0] < k || right[1] < k || right[2] < k) return -1;
        int ans = n - j;
        
        vector<int> left(3, 0);
        for (int i = 0; i < n; i++) {
            left[s[i] - 'a']++;
            if (j == i) {
                right[s[j] - 'a']--;
                j++;
            }
            while (j < n && left[s[j] - 'a'] + right[s[j] - 'a'] > k) {
                right[s[j] - 'a']--;
                j++;
            }
            ans = min(ans, i + 1 + n - j);
        }
        return ans;
    }
};
// 012345678901, n = 12
// aabaaaacaabc
// 012
