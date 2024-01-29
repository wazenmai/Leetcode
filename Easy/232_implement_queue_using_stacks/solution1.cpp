/**
 * Title:  Implement Queue using Stacks (Leetcode Easy 232)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, Janurary, 2024
 * Method: Use second stack to reverse the order of first stack
 */

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}
    
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int v = s1.top();
        s1.pop();
        return v;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// s1: 3, 2, 1
// s2: 
// push 1, 2
// 
