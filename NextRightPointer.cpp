#include <iostream>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode *leftmost = root;
    if(!root) return;
    while (leftmost->left) {
      root = leftmost;
      while (root) {
        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : NULL;
        root = root->next;
      }
      leftmost = leftmost->left;
    }
  }
};

int main() {
  Solution so;
  TreeLinkNode root(0);
  so.connect(&root);
}
