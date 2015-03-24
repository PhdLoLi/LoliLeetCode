#include <iostream>
#include <vector>
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head || n <= 0) return head;
        ListNode *fast = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if(!fast) return head->next;
        ListNode *slow = head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

/* With N Judgement
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head || n <= 0) return head;
        ListNode *fast = head;
        int count = n;
        while (fast && count >= 0) {
            fast = fast->next;
            count --;
        }
        if (count > 0)  return head;
        if (count == 0) {
            fast = head;
            head = head->next;
            delete fast;
            return head;
        }
        ListNode *slow = head;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        return head;
    }
};
*/

int main() {}
