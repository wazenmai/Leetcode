/**
 * Title:  Maximum XOR of 2 numbers in Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, Jan, 2022
 * Result: Accepted
 */

struct TrieNode {
    int val;
    TrieNode *left;
    TrieNode *right;
    TrieNode(): val(0), left(nullptr), right(nullptr) {}
    TrieNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void print_tree(TrieNode *root) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->val << " ";
            return;
        }
        print_tree(root->left);
        print_tree(root->right);
    }
public:
    int findMatch(int num, TrieNode *root) {
        TreeNode *cur;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
        }
        return 0;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode(0);
        int maximum = 0;
        for (auto& n : nums) {
            TrieNode *cur = root;
            for (int i = 30; i >= 0; i--) {
                int bit = (n >> i) & 1;
                if (bit) {
                    if (!cur->right)
                        cur->right = new TrieNode(1);
                    cur = cur->right;
                } else {
                    if (!cur->left)
                        cur->left = new TrieNode(0);
                    cur = cur->left;
                }
            }
            cur->val = n;
        }
        
        // print tree - dfs
        // cout << "---Tree---\n";
        // print_tree(root);
        // cout << "\n";
        
        for (auto& n : nums) {
            cout << n << "^";
            TrieNode *cur = root;
            for (int i = 30; i >= 0; i--) {
                int bit = (n >> i) & 1;
                if (bit) {
                    cur = (cur->left) ? cur->left : cur->right;
                } else if (!bit) {
                    cur = (cur->right) ? cur->right : cur->left;
                }
            }
            maximum = max(maximum, n ^ cur->val);
            // cout << cur->val << ": " << (n ^ cur->val) << "\n";
        }
        return maximum;
    }
};
/*

000011
001010
000101
011001
001000
0000-0000-0000-0000 - 0000-0000-0000-0000
*/
