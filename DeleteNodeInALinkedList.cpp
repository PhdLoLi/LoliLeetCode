#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
//        ListNode* p = node->next;
        node->next = node->next->next;
//        delete [] p;
    }
};

int main()
{
  Solution so;
  ListNode head(2);
//  std::cout << so.hasCycle(&head) << std::endl;
}
