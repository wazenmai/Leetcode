/**
 * Title:  Maximum Running Time of N Computers (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, July, 2023
 * Method: Sorting and Prefix sum.
 */

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        // 1. Sort batteries
        sort(batteries.begin(), batteries.end());
        // 2. Get the sum of all extra batteries
        long long extra = 0;
        for (int i = 0; i < batteries.size() - n; i++) {
            extra += batteries[i];
        }
        vector<int> live(n);
        int b = batteries.size();
        for (int i = 0; i < n; i++)
            live[i] = batteries[b - n + i];
        // 3. Increase the total running time using 'extra' by increasing
        // the running time of the computer with the smallest battery
        for (int i = 0; i < n - 1; i++) {
            if (extra < (long long)(i + 1) * (live[i + 1] - live[i])) {
                return live[i] + extra / (long)(i + 1);
            }
            // Reduce 'extra' by the total power used.
            extra -= (long long)(i + 1) * (live[i + 1] - live[i]);
        }
        // 4. If there is power left, we can increase the running time of all computers.
        return live[n - 1] + extra / n;
        
    }
};

/*
Time complexity: O(mlogm), batteries length: m
- sort batteires: O(mlogm)
- Create extra and live: O(m) + O(n)
- Increase live, decrease extra: O(n)
Space complexity: O(logm) + O(n)
*/
