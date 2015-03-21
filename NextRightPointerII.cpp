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
      TreeLinkNode *parent, *p, *brother, *b;
      root -> next = NULL;
      parent = root;
      do
      {
        p = parent;
        brother = NULL;

        while(p && !p -> left && !p->right)
          p = p -> next;

        if(!p) return;

        if(p -> left)
        {
          brother = p -> left; 
          b = brother;
          if(p -> right)
          {
            b -> next = p -> right;
            b = b -> next;
          }
        }else
        {
          brother = p -> right;
          b = brother;
        }
        
        p = p -> next;

        while(p)
        {
          while(p && !p -> left && !p->right)
            p = p -> next;

          if(!p) break;

          if(p -> left)
          {
            b -> next = p -> left;
            b = b -> next;
            if(p -> right)
            {
              b -> next = p -> right;
              b = b -> next;
            }
          }else
          {
            b -> next = p -> right;
            b = b -> next;
          }
          p = p -> next;
        }
        b -> next = NULL;

        parent = brother;

      }while(parent);
    }
};

int main()
{
  Solution so;
  TreeLinkNode root(0);
  so.connect(&root);
}
