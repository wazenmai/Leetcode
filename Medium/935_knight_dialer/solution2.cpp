/**
 * Title:  Knight Dialer (Leetcode Medium 935)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, November, 2023
 * Method: There are 4 groups of numbers, (0) (4, 6) (1, 3, 7, 9) (2, 8), number in the same group share the same occrence.
 * Result: Time complexity: O(4n) = O(n), Space complexity: O(4) = O(1).
 */

class Solution {
private:
    vector<vector<int>> v = {
        {4, 6}, {6, 8}, {7, 9}, {4, 8},
        {0, 3, 9}, {}, {0, 1, 7}, {2, 6},
        {1, 3}, {2, 4}
    };
public:
    void printnum(int n, int start, vector<int>& temp) {
        if (n == 1) {
            for (auto& e: temp) {
                cout << e;
            }
            cout << ", ";
            return;
        }
        for (auto& e: v[start]) {
            temp.emplace_back(e);
            printnum(n - 1, e, temp);
            temp.pop_back();
        }
    }
    void print(int n) {
        for (int i = 0; i < 10; i++) {
            vector<int> temp = {i};
            printnum(n, i, temp);
        }
    }
    void print(vector<long long>& v) {
        for (auto& e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
    int knightDialer(int n) {
        if (n == 1) return 10;
        int mod = 1e9 + 7;
        vector<long long> temp(4, 1); // (0) (4, 6) (1, 3, 7, 9) (2, 8)
        vector<long long> last(4, 0);
        int sum = 0;
        for (int i = 2; i <= n; i++) {
            // cout << i << ": ";
            last[0] = (temp[1] * 2) % mod;
            last[1] = (temp[0] + temp[2] * 2) % mod;
            last[2] = (temp[1] + temp[3]) % mod;
            last[3] = (temp[2] * 2) % mod;
            temp = last;
            // print(last);
        }

        long long ans = 0;
        int size[4] = {1, 2, 4, 2};
        for (int i = 0; i < 4; i++) {
            ans = (ans + last[i] * size[i]) % mod;
        }
        return ans % mod;
    }
};

// Group 1: 0
// Group 2: 4 6
// Group 3: 1, 3, 7, 9
// Group 4: 2, 8

// 0: 4 6 (2) = 6
// 1: 6 8 (2) = 5
// 2: 7 9 (2) = 4
// 3: 4 8 (2) = 5
// 4: 0 3 9 (3) = 6
// 5: x
// 6: 0 1 7 (3) = 6
// 7: 2 6 (2) = 5
// 8: 1 3 (2) = 4
// 9: 2 4 (2) = 5

// n = 1, (0 - 9) 10
// n = 2, 2 + 2 + 2 + 2 + 3 + 3 + 2 + 2 + 2 = 20
// n = 3, (2 * 2) + (2 * 2) + (2 * 2) + (2 * 2) + 3 * 3 + 3 * 3 + (2 * 2) + (2 * 2) + (2 * 2) = 46
// n = 3, 6 + 5 + 4 + 5 + 6 + 6 + 5 + 4 + 5 = 46
// n = 4, 12 + 10 + 10 + 10 + 16 + 16 + 10 + 10 + 10 = 104
// n = 5, 32 + 

// 04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94
// 2 個結束在 0, 3 個結束在 4, 3 個結束在 6

// 040, 043, 049, 060, 061, 067, 160, 161, 167, 181, 183, 272, 276, 292, 294, 340, 343, 349, 381, 383, 404, 406, 434, 438, 492, 494, 604, 606, 616, 618, 672, 676, 727, 729, 760, 761, 767, 816, 818, 834, 838, 927, 929, 940, 943, 949,
// 6 個結束在 0, 6 個結束在 4
