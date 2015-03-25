#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        ListNode *cur = head, *pre = NULL;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                do {
                    ListNode *del = cur->next;
                    cur->next = cur->next->next;
                    delete del;
                } while (cur->next && cur->val == cur->next->val);
                ListNode *del = cur;
                if (pre) { //if cur not the head You can also add a dummy node
                    pre->next = cur->next;
                    cur = pre->next;
                } else {
                    head = head->next;
                    cur = head;
                }
                delete del;
                if (!cur) break; 
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }

    ListNode *deleteDuplicatesWithDummyHead(ListNode *head) {
        if (!head) return NULL;
        ListNode dummy_head(0);
        dummy_head.next = head;
        ListNode *cur = head, *pre = &dummy_head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                do {
                    ListNode *del = cur->next;
                    cur->next = cur->next->next;
                    delete del;
                } while (cur->next && cur->val == cur->next->val);
                ListNode *del = cur;
                pre->next = cur->next;
                cur = pre->next;
                delete del;
                if (!cur) break;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy_head.next;
    }

};

int main()
{
}
