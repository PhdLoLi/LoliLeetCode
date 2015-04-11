#include <iostream>
#include <vector>
using std::vector;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* Solution I
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        if(!root) return ret;
        vector<int> sol;
        pathSum(root, sum, 0, ret, sol);
        return ret;
    }
    void pathSum(TreeNode *root, int sum, int cur_sum, vector<vector<int> > &ret, vector<int> &sol) {
        if (!root->left && !root->right) {
            sol.push_back(root->val);
            if (sum == cur_sum + root->val)
                ret.push_back(sol);
            return;   
        }
        sol.push_back(root->val);
        cur_sum += root->val;
        if (root->left) {
            pathSum(root->left, sum, cur_sum, ret, sol);
            sol.pop_back();
        }
        if (root->right) {
            pathSum(root->right, sum, cur_sum, ret, sol);
            sol.pop_back();
        }
    }
};
*/
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        if(!root) return ret;
        vector<int> sol;
        pathSum(root, sum, 0, ret, sol);
        return ret;
    }
    void pathSum(TreeNode *root, int sum, int cur_sum, vector<vector<int> > &ret, vector<int> &sol) {
        sol.push_back(root->val);
        cur_sum += root->val;
        if (!root->left && !root->right) {
            if (sum == cur_sum) ret.push_back(sol);
        } else {
            if (root->left) pathSum(root->left, sum, cur_sum, ret, sol);
            if (root->right) pathSum(root->right, sum, cur_sum, ret, sol);
        }
        sol.pop_back();
    }
};
int main() {
}
