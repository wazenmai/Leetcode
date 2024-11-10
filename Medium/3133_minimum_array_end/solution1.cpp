/**
 * Title:  Minimum Array End (Leetcode Medium 3133)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, November, 2024
 * Result: Time complexity O(logy) <= O(64). Space complexity O(logy), where x is the biggest possible long long.
 */

class Solution {
public:
    long long minEnd(int n, int x) {
        // Step 1. Get info: # of cand, # of bits, zero position
        int temp = x;
        int b = 0;
        vector<int> zeros;
        while (temp > 0) {
            int v = temp & 1;
            if (v == 0)
                zeros.emplace_back(b);
            temp >>= 1;
            b++;
        }
        long long cand = 1 << ((int)zeros.size());
        // Step 2. Calculate final # of bits and # of transformation
        int ans_b = b;
        if (n > cand) { // first time add bit, candidate no change
            n -= cand;
            zeros.emplace_back(ans_b);
            ans_b++;
        }
        while (n > cand) { // Whenever add one bit, # of candidate *= 2
            n -= cand;
            cand <<= 1;
            zeros.emplace_back(ans_b);
            ans_b++;
        }
        n -= 1; // count from zero
        // Step 3. Calculate ans based on remain n and zero position
        long long ans = x;
        for (auto& zero: zeros) {
            int v = n & 1;
            if (v == 1) {
                ans |= (1LL << zero);
            }
            n >>= 1;
        }
        ans |= (1LL << (ans_b - 1)); // significant bit
        return ans;
    }
};
// 1. count # of ones in x, # of bits in x
// 2. (b - ones) * 2 = when having same bits as x, # of transformation it have
// 3. when add one bits, there are (b - ones * 2) * 2^n transformation


// 100  -> 4, n = 3 -> 2
// 101
// 110
// 111 -> 1
// 1100 -> 1

// 001, n = 3, cand=1  -> n = 2, cand=1, ans_b=2
// 011, n = 2, cnad=1 -> n = 1, cand = 2, ans_b = 3
// 101        -> 2
// 111

// x = 001, n = 4, cand = 1 -> n = 3, cand = 1, ans_b = 2
// x = 011, n = 3, cand = 1 -> n = 2, cand = 2, ans_b = 3

// 010, n = 5, cand = 2 -> n = 3, cand = 4, ans_b = 3
// 011
// 110
// 111
//1010

// 1000 -> 0
// 1111

// 321098765432109876543210
// 011011011100001110001101 = 7193485, bits=23, n = 6715154, cand=1024
// 111011011100001110001101, n = 6714130, bit=24, cand=1024

// 110011001110111111111100011110001111
// 100011001110111111111100011110001111
