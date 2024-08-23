/**
 * Title:  Number Complement (Leetcode Easy 476)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, August, 2024
 */

class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0; 
        while (num & mask) {
            mask <<= 1;
        }
        return (~num) ^ (mask);
    }
};
