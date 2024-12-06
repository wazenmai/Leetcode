/**
 * Title:  Maximum Number of Integers to Choose From a Range I (Leetcode Medium 2554)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, December, 2024
 * Method: Use an unordered_set to store the banned. Then iterate the range to find the maximum number of integers to choose from a range I.
 * Result: Time complexity is O(n), space complexity is O(m). n = n, m = banned.size().
 */

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> us;
        for (int& b: banned) {
            us.insert(b);
        }
        int sum = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (us.find(i) != us.end()) continue;
            sum += i;
            cnt++;
            if (sum > maxSum) break;
        }
        return (sum > maxSum) ? cnt - 1 : cnt;
    }
};
