/**
 * Title:  Pairs of songs with total durations devisible by 60 (Leetcode Medium 1010)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Jan, 2022
 * Method: O(n^2)
 * Result: TLE
 */

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if ((time[i] + time[j]) % 60 == 0)
                    ans++;
            }
        }
        
        return ans;
    }
};
