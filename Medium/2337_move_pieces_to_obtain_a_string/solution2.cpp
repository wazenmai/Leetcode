/**
 * Title:  Move Pieces to Obtain a String (Leetcode Medium 2337)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, December, 2024
 * Method: Two pointer. Skip the space and check whether start[i] and target[j] are the same. If it is a 'L', make sure i >= j. If it is a 'R', make sure i <= j.
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;
            if (i >= n && j >= n) return true;
            if (i >= n || j >= n) return false;
            if (start[i] != target[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            i++;
            j++;
        }
        return true;
    }
};
