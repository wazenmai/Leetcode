/**
 * Title:  Valid Parenthesis String (Leetcode Medium 678)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, April, 2024
 * Method: Use two stacks to record the index of '(' and '*' respectively. When we meet ')', we first try to match it with '('. 
    * If there is no '(', we try to match it with '*'. If there is no '(' and '*', we return false. 
    * After that, we check the remaining '(' and '*' that can balance them. If '(' appears after '*', we return false.
    * If there are still '(' left, we return false. Otherwise, we return true.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') left.push(i);
            else if (s[i] == '*') star.push(i);
            else {
                if (!left.empty()) left.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
        }
        // check remaining '(' and '*' that can balance them
        while (!left.empty() && !star.empty()) {
            // '(' appears after '*'
            if (left.top() > star.top()) return false;
            left.pop();
            star.pop();
        }
        return left.empty();
    }
};
