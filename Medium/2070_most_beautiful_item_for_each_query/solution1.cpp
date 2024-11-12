/**
 * Title:  Most Beautiful Item for Each Query (Leetcode Medium 2070)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, November, 2024
 * Method: Sort the items accendingly, use an array to record maximum beauty from 0 to i, then binary search to find the final number id <= q.
 * Result: Time complexity O(nlogn + mlogn), space complexity O(n).
 */

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        vector<int> beauty(n, 0);
        beauty[0] = items[0][1];
        for (int i = 1; i < n; i++) {
            beauty[i] = max(beauty[i - 1], items[i][1]);
        }
        
        function<int(int)> bs = [&](int v) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (items[mid][0] > v) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l - 1;
        };

        int m = queries.size();
        vector<int> ans(m, 0);
        for (int i = 0; i < m; i++) {
            if (queries[i] >= items[n - 1][0]) { // >= max_num: maximum beauty
                ans[i] = beauty[n - 1];
            } else if (queries[i] < items[0][0]) { // < min_num, no ans
                continue;
            } else { // binary search find the final number id <= q
                int id = bs(queries[i]);
                ans[i] = beauty[id];
            }
        }
        return ans;
    }
};
