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
    vector<int> inorderTraversal(TreeNode *root) {
      vector<int> result; 
      stack<TreeNode *> st;
      TreeNode *node = root;
      while(!st.empty() || node)
      {
        if(node)
        {
          st.push(node);
          node = node -> left;
        }else
        {
          node = st.top();
          st.pop();
          result.push_back(node -> val);
          node = node -> right;
        }
      }
      return result;
    }
};

int main()
{
  Solution so;
  TreeNode root(2);
  so.inorderTraversal(&root);
}
