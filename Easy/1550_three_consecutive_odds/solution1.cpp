/**
 * Title:  Three Consecutive Odds (Leetcode Easy 1550)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, July, 2024
 */

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 2; i < n; i++) {
            if ((arr[i - 2] & 1) && (arr[i - 1] & 1) && (arr[i] & 1))
                return true;
        }
        return false;
    }
};
