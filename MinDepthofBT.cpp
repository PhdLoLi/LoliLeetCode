#include <iostream>
using std::min;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* Solution I return depth
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) 
            return 1;
        else if (root->left && !root->right)
            return minDepth(root->left) + 1;
        else if (!root->left && root->right)
            return minDepth(root->right) + 1;
        else 
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
*/
/* Solution I' */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) 
            return 1;
        int min_left = INT_MAX;
        int min_right = INT_MAX;
        if (root->left) min_left = minDepth(root->left) + 1;
        if (root->right) min_right = minDepth(root->right) + 1;
        return min(min_left, min_right);
    }
};
int main(int argc, const char *argv[])
{
  return 0;
}
