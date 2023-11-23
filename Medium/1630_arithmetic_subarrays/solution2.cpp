/**
 * Title:  Arithmetic Subarrays(Leetcode Medium 1630)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, November, 2023
 * Method: First sort the array and store the index, iterate the query , check whether the diff is correct.
 * Result: Time complexity: O(nlogn + mn), Space complexity: O(n)
 */

class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m, true);
        vector<pair<int, int>> arr; // sorted num, index

        for (int i = 0; i < n; i++) {
            arr.emplace_back(make_pair(nums[i], i));
        }

        sort(arr.begin(), arr.end(), compare);

        for (int i = 0; i < m; i++) {
            // cout << i << ": " << l[i] << "~" << r[i] << "\n"; 
            if (r[i] - l[i] + 1 <= 2) continue;
            int diff = -1;
            int last = 1e6;
            for (int j = 0; j < n; j++) {
                
                if (arr[j].second >= l[i] && arr[j].second <= r[i]) {
                    // cout << "(" << arr[j].first << "," << arr[j].second << "): " << diff << " " << last << "\n";
                    if (last == 1e6) {
                        last = arr[j].first;
                    } else if (diff == -1){
                        diff = arr[j].first - last;
                        last = arr[j].first;
                    } else {
                        if (arr[j].first - last != diff) {
                            ans[i] = false;
                            break;
                        }
                        last = arr[j].first;
                    }
                }
            }
        }
        return ans;
    }
};

// 3 4 5 6 7 9
// 4 0 2 1 5 3