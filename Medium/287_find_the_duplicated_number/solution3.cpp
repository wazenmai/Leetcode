/**
 * Title:  Find the Duplicated Number (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, September, 2023
 */

 /* Tortoise Method (Floyd's method)
 Ex: [1, 3, 4, 2, 2]
 Step 1. Consider the number array as link list, since there is at most n unique numbers but has n + 1 elements,
        so there must be duplicate.
        1 3 4 2 2
        0 1 2 3 4
        0 -> 1 -> 3 -> 2 -> 4
                       |____|
        3 1 4 2 3
        0 1 2 3 4
        0 -> 3 -> 2 -> 4 
             |_________|
        `O` (original start point)
        `S` (start point of cycle)
        `M` (1st meeting point of slow and fast)
Step 2. Use slow and fast pointer to find meeting point and the start point of cycle (the duplicate number is the
        start point and the end point of cycle, because it will eventually go back to duplicate number so it will 
        also be the start point)
Step 2.1 Both start from `O`, Slow walks 1 step, Fast walks 2 step, eventually they will meet on the cycle.
        Let a = dist(`O`, `S`),
        When slow get on `S`, it walks `a` steps, 
        and fast walks `2a` steps = `a` steps on cycle 
        => dist(slow, fast) = a % c
        => It need c - (a % c) iteration for fast to meet slow, since every iteration fast can get closer to slow for 1 step.
        `a`: distance from `O` to `S`
        `c`: the length of cycle

        When slow and fast meet at `M`, let's say slow walk `x` steps.
        x - a // steps that slow walk on cycle 
        = c - (a % c) // steps that fast meet slow after slow step on `S`
        x = a + c - (a % c), since a - a % c = multiple of c, x is the multiple of c = multiple of cycle length

        `x`: # iterations before they meet = steps between slow and fast
Step 2.2 Let slow stay on the `M`, and fast start from `O`, both walk 1 step each iteration, the point they meet is the duplicate number point `S`.
        We know that x - a is the distance (`S`, `M`), and a is dist(`O`, `S`), so after a iteration, slow will eventually walk (x - a) + a = x steps
        on the cycle, and x is the multiple of cycle length, which means slow walk back to the starting point of cycle `S`.
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (slow != fast);
        return slow;
    }
};
