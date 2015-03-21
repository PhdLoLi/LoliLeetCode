#include <iostream>
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *leftmost = root, *current;

    while (leftmost) {
      while (root && !root->left && !root->right)
        root = root->next;
      if (!root) return;
      leftmost = root->left ? root->left : root->right;

      current = leftmost;
      while (root) {
        if (root->left) {
          if (current != root->left) {
            current->next = root->left;
            current = current->next;
          } 
        } 
        if (root->right) {
          current->next = root->right;
          current = current->next;
        }
        root = root->next;
      }
      current->next = NULL;
      root = leftmost;
    }
  }
};

int main()
{
  Solution so;
  TreeLinkNode root(0);
  so.connect(&root);
}
