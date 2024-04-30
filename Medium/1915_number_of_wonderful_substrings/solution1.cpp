/**
 * Title:  Number of Wonderful Substrings (Leetcode Medium 1915)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, April, 2024
 * Method: 
    * 1. Use binary mask to indicate the occurance. if mask == 0 or only one bit is 1, then it is a wonderful substring.
    * 2. Substring (2, 5) can be represented as (0, 5) ^ (0, 1).
    * 3. Use a map to store the occurance of mask. Since the mask is 10 bits, we can use a vector to store the occurance. (accessing vector is faster than map, since map's constant is larger than vector's constant)
    * 4. For each character, we can find number in map to satisfy X^cur=0->X=cur, X^cur=(1<<0)->X=(1<<0)^cur, X^cur=(1<<1)->X=(1<<1)^cur...
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.length();
        long long ans = 0;
        vector<int> m(1024, 0);
        m[0] = 1;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur ^= (1 << (word[i] - 'a'));
            for (int j = 0; j < 10; j++) {
                ans += m[cur ^ (1 << j)];
            }
            ans += m[cur];
            m[cur]++;
            // cout << i << ", " << word[i] << ": " << cur << ", " << ans << "\n";
        }
        return ans;
    }
};

// exactly 0: find number of X where X^cur=0 => X=cur
// exactly 1 a: find number of X where X^cur=(1<<0) => X=(1<<0)^cur
// exactly 1 b: find number of X where X^cur=(1<<1) => X=(1<<1)^cur

// dp[i]: ans of word[0:i]
// (2, 5) = (0, 5) ^ (0, 1)

// m: 0 - 0. 01 - 1, 11 - 1
// 0: cur=01, ans=1
// 1: b cur=11, ans=2
// 2: a cur=10, 2+1+1

// m: 0-1. 01-1. 10-1.
// 0: cur=01, ans=1
// 1: cur=00, ans=2
// 2: cur=10, ans=4
// 3: cur=00,  
