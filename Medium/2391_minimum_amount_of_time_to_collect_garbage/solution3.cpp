/**
 * Title:  Minimum Amount of Time to Collect Garbage (Leetcode Medium 2391)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, November, 2023
 * Method: Use array to store seperate variable.
 * Result: Time complexity O(n), space complexity O(1)
 */

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int ans = 0;
        int temp[3] = {0, 0, 0};
        bool flag[3];
        for (int i = 0; i < n; i++) {
            flag[0] = flag[1] = flag[2] = false;
            for (char& c: garbage[i]) {
                if (c == 'M') {
                    flag[0] = true;
                } else if (c == 'G') {
                    flag[1] = true;
                } else if (c = 'P'){
                    flag[2] = true;
                }
                ans += 1;
            }
            for (int j = 0; j < 3; j++) {
                if (flag[j]) {
                    ans += temp[j];
                    temp[j] = 0;
                }
            }
           
            if (i < n - 1) {
                temp[0] += travel[i];
                temp[1] += travel[i];
                temp[2] += travel[i];
            }
        }
        return ans;
    }
};
