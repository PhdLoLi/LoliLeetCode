#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* Solution I 
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }
    void sumNumbers(TreeNode *root, int path, int &sum) {
        path += root->val;
        if (!root->left && !root->right) sum += path;
        if(root->left) sumNumbers(root->left, path * 10 , sum);
        if(root->right) sumNumbers(root->right, path * 10 , sum);
    }
};
*/
/* Solution II */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }
    int sumNumbers(TreeNode *root, int path) {
        if (!root) return 0;
        path += root->val;
        if (!root->left && !root->right) return path;
        return sumNumbers(root->left, path * 10) + sumNumbers(root->right, path * 10);
    }
};
int main() {
}
