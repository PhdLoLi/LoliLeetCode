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
        vector<ListNode *> v;
        while (head) {
            v.push_back(head);
            head = head->next;
        }
        head = v[0];
        
        if (n == v.size()) {
            head = head->next;
            delete v[0];
        } else if (n < v.size()){
           v[v.size() - n - 1]->next = v[v.size() - n]->next;
           delete v[v.size() - n];
        }
        return head;
    }
};
int main() {}
