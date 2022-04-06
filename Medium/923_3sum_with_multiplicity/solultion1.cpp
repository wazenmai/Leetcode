/**
 * Title:  3sum with Multiplicity (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, April, 2022
 * Result: TLE (O(n^3))
 */

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> ht;
        for (auto& x : arr)
            ht[x]++;
        int sum = 0;
        long long int ans = 0;
        int n = (int)arr.size();
        for (int i = 0; i < n - 2; i++) {
            sum += arr[i];
            for (int j = i + 1; j < n - 1; j++) {
                sum += arr[j];
                if (ht[target-sum]) {
                    for (int k = j + 1; k < n; k++) {
                        if (sum + arr[k] == target)
                            ans++;
                    }
                }
                sum -= arr[j];
            }
            sum -= arr[i];
        }
        ans = ans % 1000000007;
        return (int)ans;
    }
};
