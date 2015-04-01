#include <vector>
using std::vector;
using std::min;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<int> path(n, INT_MAX);
        path[0] = 0;
        for (int i = 0; i < m; i++) {
            path[0] += grid[i][0];
            for (int j = 1; j < n; j++) {
                path[j] = min(path[j - 1], path[j]) + grid[i][j];
            }
        }
        return path[n - 1];
    }
};
int main() {
}
