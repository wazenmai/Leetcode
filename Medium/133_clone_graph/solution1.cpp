/**
 * Title:  Clone Graph (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, Feb, 2022
 * Method: O(n) memory, dfs, visit array should save Node*.
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, vector<Node*>& visit) {
        cout << "dfs: " << node->val << "\n";
        Node* newNode = new Node(node->val);
        visit[node->val] = newNode;
        for (auto& v : node->neighbors) {
            if (!visit[v->val]) {
                cout << "neighbor-" << v->val << "\n";
                newNode->neighbors.emplace_back(dfs(v, visit));
            } else {
                newNode->neighbors.emplace_back(visit[v->val]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        
        vector<Node*> visit(101, nullptr);
        return dfs(node, visit);
    }
};
