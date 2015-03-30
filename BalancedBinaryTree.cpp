#include <cstdlib>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* V0  
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        bool tag = true;
        treeHeight(root, tag);
        return tag;
    }
    int treeHeight(TreeNode *root, bool &tag) {
        if (!tag) return -1;
        if (!root) return 0;
        int leftH = treeHeight(root->left, tag);
        int rightH = treeHeight(root->right, tag);
        if (abs(leftH - rightH) > 1) { 
            tag = false; 
            return -1;
        }
        return leftH > rightH ? ++leftH : ++rightH;
    }
};
*/
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return treeHeight(root) != -1;
    }
    int treeHeight(TreeNode *root) {
        if (!root) return 0;
        int leftH = treeHeight(root->left);
        if (leftH == -1) return -1;
        int rightH = treeHeight(root->right);
        if (rightH == -1) return -1;
        if (abs(leftH - rightH) > 1) return -1;
        return max(leftH, rightH) + 1;
    }
};

int main() {
}
