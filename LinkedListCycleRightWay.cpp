#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode *slow = head, *fast = head, *tmp;
      while(fast)
      {
        tmp = fast -> next; 
        if(tmp == NULL) return false;
        fast = tmp -> next;
        slow = slow -> next; 
        if(slow == fast)
          return true;
      }
      return false;
    }
};

int main()
{
  Solution so;
  ListNode head(2);
  std::cout << so.hasCycle(&head) << std::endl;
}
