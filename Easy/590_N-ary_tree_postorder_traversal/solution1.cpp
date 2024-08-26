/**
 * Title:  N-ary Tree Postorder Traversal (Leetcode Easy 590)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, August, 2024
 * Method: Recursion.
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
private:
    vector<int> ans;
public:
    void travel(Node* root) {
        if (root == nullptr) return;
        for (auto& child: root->children) {
            travel(child);
        }
        ans.emplace_back(root->val);
    }
    vector<int> postorder(Node* root) {
        travel(root);
        return ans;
    }
};
