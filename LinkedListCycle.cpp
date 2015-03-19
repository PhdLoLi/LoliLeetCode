#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(head == NULL) return false;
      ListNode *tail = head -> next;
      ListNode *tmp;
      while(tail)
      {
        if(tail -> next == head)
          return true;
        tmp = tail;
        tail = tail -> next;
        tmp -> next = head;
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
