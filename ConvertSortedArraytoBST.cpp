#include <iostream>
#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size() - 1); 
    }
    TreeNode *buildBST(vector<int> &num, int low, int high) {
        if (low > high) return NULL;
        int mid = (low + high) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = buildBST(num, low, mid - 1);
        root->right = buildBST(num, mid + 1, high);
        return root;
    }
};
int main () {}
