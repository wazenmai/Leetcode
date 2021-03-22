/**
 * Title:  Remove K Digits (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Mar, 2021
 */

#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>> st; // amount, value

        long long ans = arr[0];
        int st_ans = arr[0];
        int size = arr.size();
        int amount, val, pop_ele = 0;

        if (size == 1)
            return arr[0];

        st.push(make_pair(1, arr[0]));

        for (int i = 1; i < size; i++) {
            pop_ele = 0;
            while (true) {
                if (st.empty()) {
                    st.push(make_pair(1 + pop_ele, arr[i]));
                    st_ans += arr[i] * (1 + pop_ele);
                    break;
                }
                amount = st.top().first;
                val = st.top().second;
                if (val >= arr[i]) {
                    pop_ele += amount;
                    st.pop();
                    st_ans -= val * amount;
                } else {                // push value
                    st.push(make_pair(1 + pop_ele, arr[i]));
                    st_ans += arr[i] * (1 + pop_ele);
                    break;
                }
            }
            ans = (ans + st_ans % MOD) % MOD;
        }
        return ans;
    }
};
