#include <iostream>

struct TreeLinkNode{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
      if(!root) return;
      TreeLinkNode *parent, *p;
      root -> next = NULL;
      parent = root;
      while (parent -> left)
      {
        p = parent;
        while(p)
        {
          p -> left -> next = p -> right;
          if(p -> next)
            p -> right -> next = p -> next -> left;
          else
            p -> right -> next = NULL;
          p = p -> next;
        }
        parent = parent -> left;
      }
    }
};

int main()
{
  Solution so;
  TreeLinkNode root(0);
  so.connect(&root);
}
