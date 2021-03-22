/**
 * Title:  Remove K Digits (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Mar, 2021
 */

#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st; // index

        int ans = arr[0];
        int st_ans = arr[0];
        int size = arr.size();
        int pop_ele, id = 0, amount;

        if (size == 1)
            return arr[0];

        st.push(0);
        // printf("st_ans = %d, push 0\n", st_ans);

        for (int i = 1; i < size; i++) {
            printf("----\n");
            pop_ele = 0;
            while (true) {
                if (st.empty()) {
                    st.push(i);
                    st_ans += arr[i] * (1 + i);
                    // printf("st_ans = %d, push %d\n", st_ans, i);
                    break;
                }
                id = st.top();
                if (arr[id] >= arr[i]) {
                    st.pop();
                    amount = (st.empty()) ? (id + 1) : id - st.top();
                    pop_ele += amount;
                    
                    st_ans -= arr[id] * amount;
                    // printf("st_ans = %d, pop %d\n", st_ans, id);
                } else {                // push value
                    st.push(i);
                    st_ans += arr[i] * (1 + pop_ele);
                    // printf("st_ans = %d, push %d\n", st_ans, i);
                    break;
                }
            }
            ans = (ans + st_ans % MOD) % MOD;
        }
        return ans;
    }
};
