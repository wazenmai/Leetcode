/**
 * Title:  3sum with Multiplicity (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, April, 2022
 * Method: O(N^2 time), O(200) memory
 */

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = (int)arr.size();
        int mod = 1e9 + 7;
        int ans = 0;
        unordered_map<int, int> ht;
        for (int i = 0; i < n; i++) {
            ans = (ans + ht[target - arr[i]]) % mod;
            for (int j = 0; j < i; j++)
                ht[arr[i] + arr[j]]++;
        }
        return ans;
    }
};
