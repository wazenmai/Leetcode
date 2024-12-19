/**
 * Title:  Max Chunks To Make Sorted (Leetcode Medium 769)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, December, 2024
 * Result: Time complexity O(n), Space complexity O(1).
 */

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int min_num = arr[0];
        int max_num = arr[0];
        int start = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            min_num = min(min_num, arr[i]);
            max_num = max(max_num, arr[i]);
            if (min_num == start && max_num - min_num == i - start) {
                ans++;
                start = i + 1;
                min_num = 100;
                max_num = -1;
            }
        }
        return ans;
    }
};
