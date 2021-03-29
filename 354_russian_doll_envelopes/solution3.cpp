/**
 * Title:  Russian Doll Envelopes (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */

class Solution {
private:
    bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        } else {
            return a[0] < b[0];
        }
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        if (size == 0) return 0;

        vector<int> lis;
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        // LIS
        for (int i = 0; i < size; i++) {

        }
        return ans;
    }   
};