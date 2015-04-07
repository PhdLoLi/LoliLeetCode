#include <vector>
using std::vector;
/* O(n) Solution 
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        vector<bool> mark_col(n, false);
        bool mark_row = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    mark_row = true;
                    mark_col[j] = true;
                }
            }
            if (mark_row) 
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            mark_row = false;
        }
        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++) {
               if (mark_col[j])
                matrix[i][j] = 0;
            }
    }
};
*/

/* Other person's smart solution 
  void setZeroes(vector<vector<int> > &matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
}
*/

/* O(1) Solution */
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        bool mark_row = false, first_row = false;
        /* detect first row */
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) {
                first_row = true;
                break;
            }
        /* detect the whole stuff */
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    mark_row = true;
                    matrix[0][j] = 0;
                }
            }
            /* this row */
            if (mark_row) 
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            mark_row = false;
        }
        /* all cols */
        for (int j = 0; j < n; j++)
            for (int i = 1; i < m; i++) {
               if (matrix[0][j] == 0)
                matrix[i][j] = 0;
            }
        /* first row */
        if (first_row)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
    }
};
int main () {
}
