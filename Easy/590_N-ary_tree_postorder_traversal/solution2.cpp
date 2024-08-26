/**
 * Title:  N-ary Tree Postorder Traversal (Leetcode Easy 590)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, August, 2024
 * Method: Iteration. We can traverse the tree in preorder (root->right->left) and then reverse the result. For traversing children from right to left, we can use a stack (FILO) to store the children.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<Node*> parent;
        parent.push(root);
        while (!parent.empty()) {
            auto v = parent.top();
            parent.pop();
            ans.emplace_back(v->val);
            for (auto& child: v->children) {
                if (child == nullptr) continue;
                parent.push(child);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
