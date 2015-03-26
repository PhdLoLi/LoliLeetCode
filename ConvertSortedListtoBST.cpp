#include <iostream>
#include <vector>
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int num = 0;
        for (ListNode *p = head; p != NULL; p = p->next)
            num++;
        return buildBST(head, num - 1);
    }
    TreeNode *buildBST(ListNode *head, int len) {
        if (len < 0) return NULL;
        ListNode *mid = head;
        int left_len = 0;
        for (; left_len < len/2; left_len++)
            mid = mid->next;
        TreeNode *root = new TreeNode(mid->val);
        root->left = buildBST(head, left_len - 1);
        root->right = buildBST(mid->next, len - left_len - 1);
        return root;
    }
};
*/
// Very Clever Way!!! O(n) Time Complexity
    TreeNode *buildBST(ListNode *&head, int len) {
        if (len < 0) return NULL;
        int left_len = len / 2;
        TreeNode *left_child = buildBST(head, left_len - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        root->left = left_child;
        root->right = buildBST(head, len - left_len - 1);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int num = 0;
        for (ListNode *p = head; p != NULL; p = p->next)
            num++;
        return buildBST(head, num - 1);
    }


int main () {}
