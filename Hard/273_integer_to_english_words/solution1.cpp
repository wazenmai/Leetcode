/**
 * Title:  Integer to English Words (Leetcode Hard 273)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, August, 2024
 */

class Solution {
private:
    vector<string> nums = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> middle = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
public:
    string helper(int num) {
        string res = "";
        int hundred = num / 100;
        int ten = num / 10 % 10;
        int digit = num % 10;
        if (hundred != 0) {
            res += (nums[hundred - 1] + " Hundred ");
        }
        if (ten == 1) {
            res += (middle[digit] + " ");
        } else {
            if (ten != 0) {
                res += (tens[ten - 1] + " ");
            }
            if (digit != 0) {
                res += (nums[digit - 1] + " ");
            }
        }
        return res;
    }
    string numberToWords(int num) {
        vector<int> check = {1000000000, 1000000, 1000};
        string ans = "";
        if (num == 0) return "Zero";
        
        int billion = num / 1000000000;
        int million = num % 1000000000 / 1000000;
        int thousand = num % 1000000 / 1000;

        if (billion != 0) {
            ans += helper(billion);
            ans += ("Billion ");
        }
        if (million != 0) {
            ans += helper(million);
            ans += ("Million ");
        }
        if (thousand != 0) {
            ans += helper(thousand);
            ans += ("Thousand ");
        }
        int base = num % 1000;
        ans += helper(base);
        if (ans[ans.size() - 1] == ' ')
            ans.pop_back();
        return ans;
    }
};
