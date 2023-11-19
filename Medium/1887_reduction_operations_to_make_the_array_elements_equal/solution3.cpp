/**
 * Title:  Reduction Operations to Make the Array Elements Equal (Leetcode Medium 1887)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, November, 2023
 * Method: Use big arr to count the occurance of each number, ready = the # of numbers that are already been reduced.
    * n - ready means the # of operations we need to reduce the reset number to i.
 * Result: Time complexity O(n), space complexity O(n)
 */

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int arr[50001];
    int reductionOperations(vector<int>& nums) {
        int mini = 5e5;
        int largest = 0;
        int n = nums.size();
        for (int& num: nums) {
            arr[num]++;
            mini = min(num, mini);
            largest = max(num, largest);
        }
        int ans = 0;
        int ready = arr[mini];
        for (int i = mini + 1; i <= largest; i++) {
            if (arr[i] > 0) {
                ans += (n - ready);
                ready += arr[i];
            }
        }
        return ans;
    }
};
