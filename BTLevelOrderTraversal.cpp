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
/* Solution I two queue
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;    
        queue<TreeNode *> q_node;
        queue<int> q_level;
        if (root) {
            q_node.push(root);
            q_level.push(0);
        }
        while (!q_node.empty()) {
            TreeNode *front = q_node.front();
            int level = q_level.front();
            if (level == ret.size()) {
                ret.push_back(vector<int>(0, 0));
            }
            ret[level].push_back(front->val);
            if (front->left) {
                q_node.push(front->left);
                q_level.push(level + 1);
            } 
            if (front->right)
            {
                q_node.push(front->right);
                q_level.push(level + 1);
            }
            q_node.pop();
            q_level.pop();
        }
        return ret;
    }
};
*/
/* Solution II One queue NodePair
struct NodePair {
    TreeNode *node;
    int level;
    NodePair(TreeNode *root, int num) : node(root), level(num) {}
};
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;    
        queue<NodePair> q_node;
        if (root) q_node.push(NodePair(root, 0));
        while (!q_node.empty()) {
            TreeNode *front = q_node.front().node;
            int level = q_node.front().level;
            if (level == ret.size()) {
                ret.push_back(vector<int>(0, 0));
            }
            ret[level].push_back(front->val);
            if (front->left) q_node.push(NodePair(front->left, level + 1));
            if (front->right) q_node.push(NodePair(front->right, level + 1));
            q_node.pop();
        }
        return ret;
    }
};
*/
/* Solution III Two vector currLevel, nextLevel */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
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
        return ret;
    }
};
/* Solution IV DFS preorder Other person's
vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
} 
 */
int main() {
}
