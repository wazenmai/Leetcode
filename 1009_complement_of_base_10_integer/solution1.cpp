/**
 * Title:  Complement of Base 10 Integer (Leetcode Easy 1009)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, Jan, 2022
 * Method: xnor
 */

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 0;
        
        int nbits = 0;
        int base = 1;
        for (int i = 0; i <= 30; i++) {
            if (n < base)
                break;
            if (n >= base)
                nbits++;
            base *= 2;
        }
        
        int xnor_num = 0;
        base = 1;
        for (int i = 0; i < nbits; i++) {
            xnor_num += base;
            base *= 2;
        }
        
        // cout << base << " " << nbits << " " << xnor_num;
        
        return (xnor_num ^ n);
    }
};
