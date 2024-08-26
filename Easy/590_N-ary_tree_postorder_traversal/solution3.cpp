/**
 * Title:  N-ary Tree Postorder Traversal (Leetcode Easy 590)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, August, 2024
 * Method: Iteration. Stack `s` store the nodes from left to right, while taking out from right to left to store in stack `rev`. Finally, we can get the postorder traversal by taking out from `rev`.
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
        stack<Node*> s;
        stack<Node*> rev;
        if (root != nullptr)
            s.push(root);
        while (!s.empty()) {
            auto v = s.top();
            s.pop();
            rev.push(v);
            for (auto child: v->children) {
                if (child == nullptr) continue;
                s.push(child);
            }
        }
        vector<int> ans;
        while (!rev.empty()) {
            ans.emplace_back(rev.top()->val);
            rev.pop();
        }
        return ans;
    }
};
