#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/* LeetCode Answer
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *pA = headA, *pB = headB, *tailA = NULL, *tailB = NULL;
        while (pA != pB) {
            if (!pA->next && !pB->next) return NULL;
            if (!pA->next) {
                tailA = pA;
                if (tailB && tailA != tailB) return NULL;
                pA = headB;
                pB = pB->next;
                continue;
            } 
            if (!pB->next) {
                tailB = pB;
                if (tailA && tailA != tailB) return NULL;
                pB = headA;
                pA = pA->next;
                continue;                
            }
            pA = pA->next;
            pB = pB->next;
        }
        return pA;     
    }
};
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *tailA = headA, *tailB = headB;
        while (tailA->next && tailB->next) {
            tailA = tailA->next;
            tailB = tailB->next;
        }
        //A is shorter one
        while (tailB->next) {
            tailB = tailB->next;
            headB = headB->next;
        }
        //B is shorter one
        while (tailA->next) {
            tailA = tailA->next;
            headA = headA->next;
        }
        if (tailA != tailB) return NULL;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;     
    }
};
int main() {
}
