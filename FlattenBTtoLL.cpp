#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *last = new TreeNode(0);
    void flatten(TreeNode *root) {
        if (!root) return;
        last->right = root;
        last->left = NULL;
        last = root;
        TreeNode *right_node = root->right;
        flatten(root->left);
        flatten(right_node);
    }
};

/* Solution II
class Solution {
public:
    TreeNode *last = new TreeNode(0);
    void flatten(TreeNode *root) {
        if (!root) return;
        last->right = root;
        last->left = NULL;
        last = root;
        if (!root->left && !root->right) return;
        else if (!root->left && root->right) flatten(root->right);
        else if (root->left && !root->right) flatten(root->left);
        else {
            TreeNode *right_node = root->right;
            flatten(root->left);
            flatten(right_node);
        }
    }
};
*/
int main() {
}
