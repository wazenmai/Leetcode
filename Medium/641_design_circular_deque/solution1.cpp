/**
 * Title:  Design Circular Deque (Leetcode Medium 641)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, September, 2024
 */

class MyCircularDeque {
private:
    struct ListNode {
        int num;
        ListNode* next;
        ListNode* prev;
        ListNode(int num_) {
            num = num_;
            next = nullptr;
            prev = nullptr;
        }
    };
    int size;
    int max_size;
    ListNode* head;
    ListNode* tail;
public:
    MyCircularDeque(int k) {
        max_size = k;
        size = 0;
        head = tail = nullptr;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        ListNode* node = new ListNode(value);
        ListNode* cur = head;
        node->next = cur;
        if (cur != nullptr) {
            cur->prev = node;
        }
        head = node;
        size++;
        if (size == 1) {
            tail = head;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        ListNode* node = new ListNode(value);
        ListNode* cur = tail;
        node->prev = cur;
        if (cur != nullptr) {
            cur->next = node;
        }
        tail = node;
        size++;
        if (size == 1) {
            head = tail;
        }
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        ListNode* cur = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete cur;
        size--;
        if (size == 0) tail = nullptr;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        ListNode* cur = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        delete cur;
        size--;
        if (size == 0) head = nullptr;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return head->num;
    }

    int getRear() {
        if (isEmpty()) return -1;
        return tail->num;
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == max_size);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
