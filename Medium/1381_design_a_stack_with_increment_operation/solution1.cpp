/**
 * Title:  Design a Stack With Increment Operation (Leetcode Medium 1381)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, September, 2024
 */

class CustomStack {
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int x) {
            val = x;
            next = prev = nullptr;
        }
    };
    int max_size;
    int size;
    Node* top;
    Node* bottom; // bottom -> next -> top
public:
    CustomStack(int maxSize) {
        max_size = maxSize;
        size = 0;
        top = bottom = nullptr;
    }
    
    void push(int x) {
        if (size == max_size) return;
        Node* node = new Node(x);
        if (bottom == nullptr) {
            bottom = top = node;
        } else {
            top->next = node;
            node->prev = top;
            top = node;
        }
        size++;
    }
    
    int pop() {
        if (size == 0) return -1;
        int res = top->val;
        if (size == 1) {
            bottom = top = nullptr;
        } else {
            Node* tmp = top->prev;
            tmp->next = top->prev = nullptr;
            top = tmp;
        }
        size--;
        return res;
    }
    
    void increment(int k, int val) {
        Node* cur = bottom;
        for (int i = 0; i < k; i++) {
            if (cur != nullptr) {
                cur->val += val;
            } else {
                break;
            }
            cur = cur->next;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
