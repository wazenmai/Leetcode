/**
 * Title:  Number Complement (Leetcode Easy 476)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, August, 2024
 */

class Solution {
public:
    int findComplement(int num) {
        if (num == 2147483647) return 0;
        int mask = ~0;
        long long check = 1;
        while (num >= check) {
            check *= 2;
        }
        check -= 1;
        mask ^= check;
        
        // bitset<32> x(num);
        // bitset<32> y(~num);
        // bitset<8> z(check);
        // bitset<8> a(mask); 
        // cout << x << "\n" << y << "\n";
        return (~num) ^ mask;
    }
};
