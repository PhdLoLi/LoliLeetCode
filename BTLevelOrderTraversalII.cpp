#include <vector>
#include <queue>
using std::vector;
using std::queue;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* Solution I two vector -> one vector NodePair 
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if (!root) return vector<vector<int> >();
        vector<TreeNode *> v_node;
        vector<int> v_level;
        if(root) {
            v_node.push_back(root);
            v_level.push_back(0);
        }
        for(int i = 0; i < v_node.size(); i++) {
            if (v_node[i]->left) {
                v_node.push_back(v_node[i]->left);
                v_level.push_back(v_level[i] + 1);
            }
            if (v_node[i]->right) {
                v_node.push_back(v_node[i]->right);
                v_level.push_back(v_level[i] + 1);
            }        
        }
        int level = v_level[v_level.size() - 1];
        vector<vector<int> > ret(level + 1);
        for (int i = 0; i < v_node.size(); i++) {
            ret[level - v_level[i]].push_back(v_node[i]->val);
        }
        return ret;
    }
};
*/
/* Solution II 
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;  
        queue<TreeNode *> curr;
        if (root) curr.push(root);
        while (!curr.empty()) {
            queue<TreeNode *> next;
            vector<int> ret_level;
            while(!curr.empty()) {
                TreeNode *front = curr.front();
                ret_level.push_back(front->val);
                if (front->left) next.push(front->left);
                if (front->right) next.push(front->right);
                curr.pop();
            }
            ret.push_back(ret_level);
            curr.swap(next);
        }
        std::reverse(ret.begin(), ret.end()); //Not very good... just do reverse
        return ret;
    }
};
*/
class Solution {
public:
    vector<vector<int>> ret;
    void buildVector(TreeNode *root, int depth) {
        if(root == NULL) return;
        if(ret.size() == depth)
            ret.insert(ret.begin(), vector<int>()); //Low Efficiency! insert of vector~
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
        ret[ret.size() - 1 - depth].push_back(root->val);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        buildVector(root, 0);
        return ret;
    } 
};
int main() {
}
