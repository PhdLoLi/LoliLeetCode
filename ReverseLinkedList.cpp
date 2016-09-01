#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    // iteratively 25%
    ListNode* reverseListI(ListNode* head) {
        ListNode *pre = NULL;
        while (head) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }

    // recursively 27.84
    ListNode* reverseListII(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode* p = reverseListII(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
    // dummy node insert from beginning 27.84
    ListNode* reverseListIII(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        while (head) {
            ListNode* tmp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = tmp;
        }
        return dummy->next;
    }

};
int main() {
}
