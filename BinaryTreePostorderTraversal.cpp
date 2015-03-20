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
      TreeNode *last = NULL;
      while(!st.empty() || node)
      {
        if(node)
        {
          st.push(node);
          node = node -> left;
        }else
        {
          if(st.top() -> right && st.top() -> right != last)
           node = st.top() -> right;
          else
          {
            last = st.top();
            st.pop();
            result.push_back(last -> val);
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
