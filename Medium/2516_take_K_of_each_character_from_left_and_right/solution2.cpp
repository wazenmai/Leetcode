/**
 * Title:  Take K of Each Character From Left and Right (Leetcode Medium 2516)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, November, 2024
 * Method: Only maintain one count vector. After computing whole array frequency, we iterate i from right to left and take out i-th element, if the frequency of the element is less than k, we move j to left until the frequency of the element is greater than or equal to k. Then we update the answer.
 * Result: Time complexity O(n), space complexity O(1). // n is the length of the string.
 */
class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> cnt(3, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
        }
        if (cnt[0] < k || cnt[1] < k || cnt[2] < k) return -1;
        int ans = n;
        int i = n - 1, j = n - 1;
        while (i >= 0) {
            cnt[s[i] - 'a']--;
            while (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
                cnt[s[j] - 'a']++;
                j--;
            }
            i--;
            ans = min(ans, i + n - j);
        }
        return ans;
    }
};

