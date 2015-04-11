#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*Solution I Low efficiency 
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSum(root, sum, 0);    
    }
    bool hasPathSum(TreeNode *root, int sum, int cur_sum) {
        if (!root) return false;
        if (!root->left && !root->right) return sum == cur_sum + root->val;
        cur_sum += root->val;
        return hasPathSum(root->left, sum, cur_sum) || hasPathSum(root->right, sum, cur_sum);
    }
};
 */
/* Solution II */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        int cur_sum = 0;
        return hasPathSum(root, sum, cur_sum);    
    }
    bool hasPathSum(TreeNode *root, int sum, int cur_sum) {
       if (!root->left && !root->right) return sum == cur_sum + root->val;
       cur_sum += root->val;
       if (root->left && !root->right) return hasPathSum(root->left, sum, cur_sum);
       if (!root->left && root->right) return hasPathSum(root->right, sum, cur_sum);
       if (root->left && root->right) return hasPathSum(root->left, sum, cur_sum) || hasPathSum(root->right, sum, cur_sum);
    }
};
int main() {
}
