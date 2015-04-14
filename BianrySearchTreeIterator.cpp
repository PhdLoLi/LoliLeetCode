#include <stack>
using std::stack;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left; 
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *root = s.top();
        s.pop();
        int ret = root->val;
        root = root->right;
        while (root) {
            s.push(root);
            root = root->left;
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main() {
}
