#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = NULL;
        while (fast) {
            ListNode *tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        while (slow) {
            if (slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};

int main()
{
  Solution so;
  ListNode head(2);
//  std::cout << so.hasCycle(&head) << std::endl;
}

