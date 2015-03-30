#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return NULL;
        ListNode *dummy = new ListNode(0), *p = dummy;
        dummy->next = head;
        while (head && head->next) {
            p->next = head->next;
            head->next = p->next->next;
            p->next->next = head;
            p = head;
            head = head -> next;
        }
        return dummy->next;
    }
};
int main() {
}
