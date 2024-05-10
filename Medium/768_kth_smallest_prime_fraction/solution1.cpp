/**
 * Title:  K-th Smallest Prime Fraction (Leetcode Medium 786)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, May, 2024
 * Method: Sort by vector to get kth smallest fraction.
 * Result: Time complexity O(n^2logn^2), space complexity O(n^2)
 */

class Solution {
public:
    static bool compare(pair<double, vector<int>>& a, pair<double, vector<int>>& b) {
        return a.first < b.first;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, vector<int>>> v;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                v.emplace_back(make_pair((double)arr[i] / arr[j], vector<int>{arr[i], arr[j]}));
            }
        }
        sort(v.begin(), v.end(), compare);
        // for (auto& ele: v) {
        //     cout << ele.first << ": " << ele.second[0] << "," << ele.second[1] << "\n";
        // }
        return v[k - 1].second;
    }
};
