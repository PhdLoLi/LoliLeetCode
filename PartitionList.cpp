#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *small = dummy;
        head = dummy;
        while (head->next) {
            if (head->next->val >= x) {
                head = head->next;
                continue;
            }
            if (head == small) {
                head = head->next;
                small = head;
            } else {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = small->next;
            small->next = tmp;
            small = tmp;
            }
        }
        return dummy->next;
    }
};
int main() {
}
