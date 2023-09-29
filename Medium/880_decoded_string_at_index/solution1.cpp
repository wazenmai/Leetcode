/**
 * Title:  Decoded String At Index (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, September, 2023
 * Method: First calculate the length of decoded string, then use math to get the kth character. O(N)
 */

class Solution {
public:
    string decodeAtIndex(string& s, int k) {
        long long tape = 0;
        for (auto& c: s) {
            if (c >= '0' && c <= '9') {
                tape *= (c - '0');
            } else {
                tape++;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                tape /= (s[i] - '0');
                k %= tape;
            } else {
                if (k == 0 || tape == k)
                    return string("") + s[i];
                tape--;
            }
        }
        return "";
    }
};

/*
string = prob3slve4 , k = 31
length of encoded string = ( 3 * 4 + 4 )* 4 = 64 

lentgh = 64, k = 31
at 10th char = 4 -> length = 64 / 4 = 16
k = 31 % 16 = 15

lentgh = 16, k = 15
at 9th char = e
length = 16 - 1 = 15

lentgh = 15, k = 15
at 8th char = v
k == length -> then our desire char is v
*/
