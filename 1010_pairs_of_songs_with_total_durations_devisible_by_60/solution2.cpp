/**
 * Title:  Pairs of songs with total durations devisible by 60 (Leetcode Medium 1010)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Jan, 2022
 * Method: We can count the number of songs with (length % 60) equal to r, and store that in an array of size 60. O(n)
 * Result: Accepted
 */

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans = 0;
        vector<int> arr(61, 0); // (size, value)
        
        for (int i = 0; i < n; i++)
            arr[time[i] % 60]++;
        
        for (int i = 0; i < 30; i++) {
            if (i == 0)
                ans += (arr[i] > 1) ? (arr[i] * (arr[i] - 1) / 2) : 0;
            else
                ans += (arr[i] * arr[60-i]);
        }
        
        ans += (arr[30] > 1) ? (arr[30] * (arr[30] - 1) / 2) : 0;
        
        return ans;
    }
};
