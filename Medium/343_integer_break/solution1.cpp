/**
 * Title:  Integer Break (Leetcode Medium 343)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, October, 2023
 */

class Solution {
public:
    int recursive(int n) {
        // cout << n << "\n";
        if (n <= 4)
            return n;
        return 3 * recursive(n - 3);
    }
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
            return 4;
        return 3 * recursive(n - 3);
    }
};
// 2: 1
// 3: 2
// 4: 4
// 5: 6
// 6: 9
// 7: 12
// 8: 18
// 9: 27

/* Math Proof of finding 3 * integerbreak(n - 3), why is 3? 
Let n can break into (n / x) x's, then the product is x^(n / x)
Take the derivative of x^(n / x) -> (n / x) * x^(n / x - 1) * (1 - ln(x)) = n * x^(n / x - 2) *  (1 - ln(x)).
The derivative is positive when x < e, and negative when x > e, equal to 0 when x = e ->
which indicates that the function is increasing when x < e, and decreasing when x > e, and x = e is its maximum.

So the best idea is to break it into nearly all e's, and 2 < e < 3.
3 is better choice than 2, because 6 = 3 * 3 > 2 * 2 * 2 = 8.
*/


