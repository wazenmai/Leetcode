/**
 * Title:  Maximum Swap (Leetcode Medium 670)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, October, 2024
 * Method: Find the rightmost digit to swap and the digit to swap with it (using stack)./
 * Result: Time complexity is O(n), Space complexity is O(n).
 */

class Solution {
public:
    int maximumSwap(int num) {
        // track max_num and make vector
        vector<int> v;
        int temp = num;
        int max_num = 0;
        vector<int> cnt(10, 0);
        while (temp > 0) {
            int t = temp % 10;
            v.emplace_back(t);
            cnt[t]++;
            max_num = max(max_num, t);
            temp /= 10;
        }
        int n = v.size();
        // find the rightmost digit to swap
        int i = n - 1;
        while (i >= 0) {
            if (v[i] == max_num) {
                i--;
                cnt[max_num]--;
                while (max_num >= 0 && cnt[max_num] == 0) {
                    max_num--;
                }
            } else {
                break;
            }
        }
        if (i < 0) return num;
        // find the digit to swap with it
        stack<int> st;
        st.push(i);
        int start = i;
        for (; i >= 0; i--) {
            if (v[i] >= v[st.top()]) {
                st.push(i);
            }
        }
        temp = v[st.top()];
        v[st.top()] = v[start];
        v[start] = temp;
        // Calculate answer
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = ans * 10 + v[i];
        }
        return ans;
    }
};
