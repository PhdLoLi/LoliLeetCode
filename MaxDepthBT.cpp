#include <iostream>
using std::max;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* Solution I 
class Solution {
public:
    int maxDepth(TreeNode *root) {
      int rightD, leftD;
      if(!root)
        return 0;

      leftD = maxDepth(root->left);
      rightD = maxDepth(root->right);

      return (leftD > rightD) ? leftD+1 : rightD+1;
    }
};
*/
/* Solution I' */
class Solution {
public:
    int maxDepth(TreeNode *root) {
      if(!root) return 0;
      return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
int main()
{
  TreeNode root(0);
  Solution so;
  std::cout << so.maxDepth(&root) << std::endl;
}
