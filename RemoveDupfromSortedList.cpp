#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/* Two pointers Solution 
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        ListNode *cur = head->next;
        ListNode *pre = head;
        while (cur) {
            if (cur->val == pre->val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return head;
    }
};
*/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode *cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                ListNode *del = cur->next;
                cur->next = del->next;
                delete(del);
            } else {
                cur = cur->next;
            }
        }
        return head;
    }

    ListNode* deleteDuplicatesNEW(ListNode* head) {
         if (!head || !head->next) return head;
         ListNode *p = head;
         while (p->next) {
             if (p->val == p->next->val) {
                 p->next = p->next->next;
             } else p = p->next;
         }
         return head;
    }
};

int main()
{
}
