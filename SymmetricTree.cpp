#include <iostream>
#include <queue>
#include <stack>
using std::queue;
using std::stack;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* DFS Recursive 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);   
    }
    bool isSymmetric(TreeNode *left_node, TreeNode *right_node) {
        if (!left_node && !right_node) return true;
        if ((!left_node && right_node) || (left_node && !right_node)) return false;
        if (left_node->val != right_node->val) return false;
        return isSymmetric(left_node->left, right_node->right) && isSymmetric(left_node->right, right_node->left);   
    }
};
*/
/* DFS Iterative Stack LIFO 
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root || !root->left && !root->right) return true;
        stack<TreeNode *> v_l;
        stack<TreeNode *> v_r;
        if (root->left) v_l.push(root->left);
        if (root->right) v_r.push(root->right);
        while (!v_l.empty() && !v_r.empty()) {
            TreeNode *l_node = v_l.top();
            TreeNode *r_node = v_r.top();
            if (l_node->val != r_node->val) return false;
            if (l_node->left) {
                v_l.push(l_node->left);
                l_node->left = NULL;
            } else {
                if (l_node->right) {
                    v_l.pop();
                    v_l.push(l_node->right);
                } else v_l.pop();
            }
            if (r_node->right) {
                v_r.push(r_node->right);
                r_node->right = NULL;
            } else {
                if (r_node->left) {
                    v_r.pop();
                    v_r.push(r_node->left);
                } else v_r.pop();
            }
        }
        if (v_l.empty() && v_r.empty()) return true;
        else return false;
    }
};*/
/* DFS Iterative Stack LIFO'
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode *> v_l;
        stack<TreeNode *> v_r;
        v_l.push(root->left);
        v_r.push(root->right);
        while (!v_l.empty() && !v_r.empty()) {
            TreeNode *l_node = v_l.top();
            TreeNode *r_node = v_r.top();
            if (!l_node && r_node || l_node && !r_node) return false;
            if (!l_node && !r_node) {
                do {
                    v_l.pop();
                    v_r.pop();
                } while (!v_l.empty() && !v_r.empty() && !v_l.top()->right && !v_r.top()->left);
                if (v_l.empty() || v_r.empty()) break;
                l_node = v_l.top();
                r_node = v_r.top();
                v_l.pop();
                v_r.pop();
                v_l.push(l_node->right);
                v_r.push(r_node->left);
            } else {
                if (l_node->val != r_node->val) return false;
                v_l.push(l_node->left);
                v_r.push(r_node->right); 
            }
        }
        if (v_l.empty() && v_r.empty()) return true;
        else return false;
    }
};
*/
/*  DFS Iterative Stack LIFO'' Follow Pre-Order Traversal
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        stack<TreeNode *> v_l;
        stack<TreeNode *> v_r;
        TreeNode *l_node = root->left;
        TreeNode *r_node = root->right;
        while ((!v_l.empty() || l_node) && (!v_r.empty() || r_node)) {
            if (!l_node && r_node || l_node && !r_node) return false;
            if (!l_node && !r_node) {
                l_node = v_l.top();
                r_node = v_r.top();
                v_l.pop();
                v_r.pop();
            } else {
                if (l_node->val != r_node->val) return false;
                if (l_node->right)
                    v_l.push(l_node->right);
                l_node = l_node->left;
                if (r_node->left)
                    v_r.push(r_node->left);
                r_node = r_node->right;
            }
        }
        if (v_l.empty() && v_r.empty() && !l_node && !r_node) return true;
        else return false;
    }
};
*/
/* BFS Iterative Queue FIFO */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> v_l;
        queue<TreeNode *> v_r;
        v_l.push(root->left);
        v_r.push(root->right);
        while (!v_l.empty() && !v_r.empty()) {
            TreeNode *l_node = v_l.front();
            TreeNode *r_node = v_r.front();
            v_l.pop();
            v_r.pop();
            if ((!l_node && r_node) || (l_node && !r_node)) return false;
            if (!l_node && !r_node) continue;
            if (l_node->val != r_node->val) return false;
            v_l.push(l_node->left);
            v_l.push(l_node->right);
            v_r.push(r_node->right);
            v_r.push(r_node->left);
        }
        if (v_l.empty() && v_r.empty()) return true;
        else return false;
    }
};
int main() {
}
