#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

      ListNode *slow = head, *fast = head, *tmp;
      while(fast)
      {
        tmp = fast -> next; 
        if(tmp == NULL) return NULL;
        fast = tmp -> next;
        slow = slow -> next; 
        if(slow == fast)
        {
          slow = head;
          while(slow != fast)
          {
            slow = slow -> next;
            fast = fast -> next;
          }
          return fast;
        }
      }
      return NULL;
    }        
};

int main()
{
  Solution so;
  ListNode head(2);
  std::cout << so.detectCycle(&head)->val << std::endl;
}
