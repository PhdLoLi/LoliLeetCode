#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *slow = head, *fast = head;
        if (!head) return head;
        int step = 0;
        while (fast->next) {
//            if (step >= k)
//                slow = slow->next;
            fast = fast->next;
            step++;
        }
        //if (k > step && k % (step + 1) == 0) return head;
        //if (k > step) {
        for (int i = 0; i < step - k % (step + 1); i++)
            slow = slow->next;            
        //}
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};
int main() {
}
