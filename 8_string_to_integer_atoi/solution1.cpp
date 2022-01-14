/**
 * Title:  String to Integer (atoi) (Leetcode Medium 8)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, Jan, 2022
 * Method: sort the end, then use the end as arrow.
 */

class Solution {
public:
    int myAtoi(string s) {
        // check leading white space
        int index = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                index = i;
                break;
            }
        }
        
        // check sign
        bool sign = true;
        if (s[index] == '-') {
            sign = false;
            index++;
        } else if (s[index] == '+') {
            index++;
        } else if (s[index] < '0' || s[index] > '9') {
            return 0;
        }
        
        // read number
        int ans = 0;
        bool out_of_bound = false;
        for (int i = index; i < n; i++) {
            // cout << i << ": " << s[i] << " " << ans << "\n";
            if (s[i] >= '0' && s[i] <= '9') {
                // check boundary
                if (ans > 214748364) {
                    out_of_bound = true;
                    break;
                } else if (ans == 214748364 && s[i] > '7' && s[i] <= '9') {
                    out_of_bound = true;
                    break;
                }
                ans = ans * 10 + (s[i] - '0');
            } else {
                break;
            }
            
        }
        
        if (out_of_bound && sign) {
            ans = 2147483647;
        } else if (out_of_bound && !sign) {
            ans = -2147483648;
        } else if (!sign) {
            ans = -ans;
        }
        return ans;
    }
};
