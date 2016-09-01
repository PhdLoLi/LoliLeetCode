#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  // my previous two pointers solution dealing with head first
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val)
            head = head->next;
        if (head == NULL) return NULL; 
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur != NULL) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else 
                pre = cur;
            cur = cur->next;
        }
        return head;
    }

    // add dummy node
    ListNode* removeElementsDummy(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else 
                p = p->next;
        }
        return head->next;
    }
};

int main()
{
  Solution so;
  ListNode head(2);
//  std::cout << so.hasCycle(&head) << std::endl;
}
