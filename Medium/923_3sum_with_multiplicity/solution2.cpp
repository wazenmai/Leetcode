/**
 * Title:  3sum with Multiplicity (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, April, 2022
 * Method: O(N^2 time), O(100N) memory
 */

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = (int)arr.size();
        vector<vector<int>> v(n, vector<int>(101, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                v[j][arr[i]]++;
            }
        }
    
        int sum = 0;
        long long int ans = 0;
        
        for (int i = 0; i < n - 2; i++) {
            if (arr[i] > target)
                continue;
            sum += arr[i];
            for (int j = i + 1; j < n - 1; j++) {
                if (arr[j] > target - sum)
                    continue;
                sum += arr[j];
                if (sum <= target && target - sum <= 100 && v[j + 1][target - sum])
                    ans += v[j + 1][target - sum];
                ans %= 1000000007;
                sum -= arr[j];
            }
            sum -= arr[i];
        }
        ans = ans % 1000000007;
        return (int)ans;
    }
};

// v[index][value] -> >= index 的格子裡有幾個 value
