/**
 * Title:  Maximum Runing Time of N Computers (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, July, 2023
 * Method: Binary Search. Time Complexity O(mlogn). m is the length of batteries, and n is the max running time.
 */

class Solution {
public:
    bool possible(int n, vector<int>& batteries, long long time) {
        // n: # computers, time: maxRunTime
        long long s = 0;
        for (int battery: batteries) {
            s += battery;
            if (s >= time) { // the battery satisfy one computer to run "time" hours
                s -= time;
                n--;
            }
            if (n == 0)
                return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0, r = 0;
        for (int battery: batteries) {
            r += battery;
        }
        r /= n;
        sort(batteries.begin(), batteries.end());
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            // cout << l << " " << r << ": " << mid << "\n";
            if (possible(n, batteries, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
