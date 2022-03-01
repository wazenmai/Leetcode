/**
 * Title:  Sort List (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Feb, 2022
 * Method: O(NlogN) merge sort
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* head, ListNode* head2, int limit1, int limit2) {
        if (head == nullptr)
            return head2;
        if (head2 == nullptr)
            return head;
        
        ListNode *cur1 = head;
        ListNode *cur2 = head2;
        ListNode *newHead, *newcur;
        if (cur1->val < cur2->val) {
            limit1--;
            newHead = newcur = cur1;
            cur1 = cur1->next;
        } else {
            limit2--;
            newHead = newcur = cur2;
            cur2 = cur2->next;
        }
        while (cur1 && cur2 && limit1 && limit2) {
            if (cur1->val < cur2->val) {
                newcur->next = cur1;
                cur1 = cur1->next;
                limit1--;
            } else {
                newcur->next = cur2;
                cur2 = cur2->next;
                limit2--;
            }
            newcur = newcur->next;
        }
        if (limit1) {
            while (limit1--) {
                newcur->next = cur1;
                cur1 = cur1->next;
                newcur = newcur->next;
            }
        }
        else if (limit2) {
            while (limit2--) {
                newcur->next = cur2;
                cur2 = cur2->next;
                newcur = newcur->next;
            }
        }
        return newHead;
    }
    
    void printList(ListNode* a, int limit) {
        ListNode* b = a;
        if (b == nullptr) {
            cout << "[]\n";
            return;
        }
        cout << "[";
        while (b != nullptr && limit--) {
            cout << b->val << " ";
            b = b->next;
        }
        cout << "]\n";
    }
    
    ListNode* mergeSort(ListNode* head, int right) {
        // cout << "mergesort: " << right << "\n";
        if (right == 0)
            return nullptr;
        if (right == 1) {
            // cout << "   " << head->val << "\n";
            return head;
        }
        int mid = right / 2;
        
        // cut the list
        ListNode *cur = head;
        for (int i = 0; i < mid - 1; i++)
            cur = cur->next;
        ListNode* nextNode = cur->next;
        cur->next = nullptr;
        
        ListNode* list1 = mergeSort(head, mid);
        ListNode* list2 = mergeSort(nextNode, right - mid);
        // cout << "merge: " << right << " " << mid << " " << right - mid << " ";
        ListNode* res = merge(list1, list2, mid, right - mid);
        // printList(res, right);
        return res;
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* cur = head;
        int n = 0;
        
        // calculate length
        while (cur != nullptr) {
            n++;
            cur = cur->next;
        }
        // cout << n << "\n";
        return mergeSort(head, n);
    }
};