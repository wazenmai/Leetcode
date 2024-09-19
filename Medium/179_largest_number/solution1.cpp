/**
 * Title:  Largest Number (Leetcode Medium 179)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, September, 2024
 */

class Solution {
public:
    static bool compare(string& a, string& b) {
        string na = a + b;
        string nb = b + a;
        return na > nb;
    }
    string largestNumber(vector<int> nums) {
        int n = nums.size();
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = to_string(nums[i]);
        }
        sort(v.begin(), v.end(), compare);
        if (v[0] == "0") return "0"; 
        string ans = "";
        for (auto& s: v) {
            ans += s;
        }
        return ans;
    }
};
