/**
 * Title:  Greatest Common Divisor Traversal (Leetcode Hard 2709)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, February, 2024
 * Method: Iterate through all numbers O(n) and find each number's prime factors O(sqrt(max_num)).
    *      Use an unordered_map to store the first occur num id for each prime factor. Then if the prime factor occurs again, connect the two numbers.
 * Result: Pass. Time Complexity: O(n * sqrt(max_num)). Space Complexity: O(n).
 */

class UnionFindSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFindSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void connect(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else if (px < py){
            parent[py] = px;
            rank[px]++;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        UnionFindSet uf(n);
        unordered_map<int, int> factor; // factor: first occur num id
        for (int i = 0; i < n; i++) {
            // Find prime factors, O(sqrt(max_num))
            int divisor = 2;
            int num = nums[i];
            while (divisor * divisor <= num) {
                if (num % divisor == 0) {
                    if (factor.find(divisor) == factor.end()) {
                        factor[divisor] = i;
                    } else {
                        uf.connect(factor[divisor], i);
                    }
                    while (num % divisor == 0) {
                        num /= divisor;
                    }
                }
                divisor++;
            }
            if (num > 1) {
                if (factor.find(num) == factor.end()) {
                    factor[num] = i;
                } else {
                    uf.connect(factor[num], i);
                }
            }
        }

        int p = uf.find(0);
        for (int i = 1; i < n; i++) {
            if (uf.find(i) != p) return false;
        }
        return true;
    }
};

// Iterate through all numbers O(n) and find each number's prime factors O(sqrt(max_num)).
// Use an unordered_map to store the first occur num id for each prime factor. Then if the prime factor occurs again, connect the two numbers.

// Time Complexity: O(n * sqrt(max_num))
// Space Complexity: O(n)

