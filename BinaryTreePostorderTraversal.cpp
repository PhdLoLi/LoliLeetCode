#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
      vector<int> result; 
      stack<TreeNode *> st;
      TreeNode *node = root;
      TreeNode *last = root;
      while(!st.empty() || node)
      {
        if(node)
        {
          st.push(node);
          node = node -> left;
        }else
        {
          node = st.top() -> right;
          if(!node)
          {
            do
            {
              node = st.top();
              st.pop();
              result.push_back(node -> val);
            }while(!st.empty() && st.top() -> right == node);
            node = NULL;
          }
        }
      }
      return result;
    }
};

int main()
{
  Solution so;
  TreeNode root(2);
  so.postorderTraversal(&root);
}
