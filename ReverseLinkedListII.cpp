#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        for (int i = 1; i < m; i++) 
            head = head->next;
        ListNode *cur = head->next, *nex = cur->next;
        for (int i = m; i < n; i++) {
            ListNode *tmp = nex->next;
            nex->next = cur;
            cur = nex;
            nex = tmp;
        }
        head->next->next = nex;
        head->next = cur;
        return dummy->next;
    }
};
int main() {
}
