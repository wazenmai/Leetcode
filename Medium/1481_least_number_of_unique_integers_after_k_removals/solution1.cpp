/**
 * Title:  Least Number of Unique Integers after K Removals (Leetcode Medium 1481)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, February, 2024
 * Method: Use unordered_map to count the number occurence, then use map to sort the occurence and decrease k by traversing the cnt.
 * Result: Time complexity O(nlogn), space complexity O(n).
 */

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int& num: arr) {
            m[num]++;
        }

        map<int, int> cnt;
        for (auto it = m.begin(); it != m.end(); it++) {
            cnt[it->second]++;
        }
        
        int ans = m.size();
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            while (k >= it->first && it->second != 0) {
                it->second--;
                ans--;
                k -= it->first;
            }
            if (k == 0) break;
        }
        return ans;
    }
};
