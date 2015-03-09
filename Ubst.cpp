#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {

      vector<TreeNode *> **e; 
      e = new vector<TreeNode *> *[n+2];
//      vector<TreeNode *> e[n+2][n+1];
      int l, i, j, r, sizeR, zeroR, zeroL, sizeL, x, y;

      for(i=0; i<n+2; i++)
      {
        e[i] = new vector<TreeNode *> [n+1];
      }

      for(i=1; i<=n; i++)
      {
        e[i][i].push_back(new TreeNode(i));
        e[i][i-1].push_back(NULL);
      }
      e[i][i-1].push_back(NULL);

      for(l=2; l<=n ;l++)
      {
        for(i=1; i<=n-l+1 ;i++)
        {
          j = i+l-1;
          for(r=i; r<=j; r++)
          {
            sizeL = e[i][r-1].size();
            sizeR = e[r+1][j].size();
            
            for(x=0; x<sizeL; x++) 
            {
              for(y=0; y<sizeR; y++)
              {
                TreeNode *newRoot = new TreeNode(r);
                newRoot -> left = e[i][r-1][x];
                newRoot -> right = e[r+1][j][y];
                e[i][j].push_back(newRoot);

              }
            }
          }
        }
      }

//      cout << " ";
//      for(i=1; i<=n; i++)
//        cout<<"  "<< i;
//      cout << endl;
//      for(j=n; j>=1; j--)
//      {
//        cout << j ;
//        for(i=1; i<=n; i++)
//        {
//          cout << "  " << e[i][j].size();
//        } 
//        cout << "" << endl;
//      }
//      vector<TreeNode *>::iterator it;
//      cout << "Total number: " << e[1][n].size() << endl;
//      for(it=e[1][n].begin(); it<e[1][n].end(); it++)
//      {
//        printPreorder(*it);
//        cout << " " << endl;
//      }
      return e[1][n];
      
    }

    void printPreorder(TreeNode * t)
    {
      if(t==NULL) return;
      cout << t->val << " -> " ;
      printPreorder(t->left);
      printPreorder(t->right);
    }

};

int main(int argc, char *argv[])
{
  Solution st;
  int n = 3; //default n
  if (argc > 1)
    n = atoi(argv[1]);
  st.generateTrees(n);
}
