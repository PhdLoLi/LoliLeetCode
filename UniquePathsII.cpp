#include <vector>
using std::vector;
/* 2D Array 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = 0;
        if (m > 0) n = obstacleGrid[0].size(); else return 0;
        int path[m][n];
        path[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < m; i++) path[i][0] = obstacleGrid[i][0] ? 0 : path[i - 1][0];  
        for (int j = 1; j < n; j++) path[0][j] = obstacleGrid[0][j] ? 0 : path[0][j - 1];
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++) {
                path[i][j] = obstacleGrid[i][j] ? 0 : path[i - 1][j] + path[i][j - 1];
            }
        return path[m - 1][n - 1];
    }
};
*/
/* One Rolling Array */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = 0;
        if (m > 0) n = obstacleGrid[0].size(); else return 0;
        int path[n];
        path[0] = 1 - obstacleGrid[0][0];
        for (int j = 1; j < n; j++) path[j] = obstacleGrid[0][j] ? 0 : path[j - 1];
        for (int i = 1; i < m; i++) {
            path[0] = obstacleGrid[i][0] ? 0 : path[0];
            for (int j = 1; j < n; j++) {
                path[j] = obstacleGrid[i][j] ? 0 : path[j] + path[j - 1];
            }
        }
        return path[n - 1];
    }
};
int main() {
}
