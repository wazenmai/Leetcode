/**
 * Title:  Decoded String At Index (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, September, 2023
 * Method: Speed Optimization
*/

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long decodeLen = 0;
        int n = s.length();
        for (int i = 0; i < n; i++){
            if (isdigit(s[i])){
                decodeLen *= s[i] - '0';
            }
            else {
                decodeLen++;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(isdigit(s[i])){
                decodeLen /= (s[i] - '0');
                k = k % decodeLen;
            }
            else{
                if(k == 0 || k == decodeLen)
                    return string(1, s[i]);
                decodeLen--;
            }
        }
        return "";
    }
};
