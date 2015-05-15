#include <vector>
using std::vector;
using std::min;
/* O(n*n) Space
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        if (m == 0) return 0;
        
        //vector<int> res(m, triangle[0][0]);
        
        for (int i = 1; i < m; i++) {
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            triangle[i][i] += triangle[i - 1][i - 1];
        }
        
        int min_sum = triangle[m - 1][0];
        for (int j = 1; j < m; j++) {
            if (triangle[m - 1][j] < min_sum)
                min_sum = triangle[m - 1][j];
        }
        
        return min_sum;
    }
};
*/
/* O(n) Space */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        if (m == 0) return 0;
        
        vector<int> res(m, triangle[0][0]);
        for (int i = 1; i < m; i++) {
            //triangle[i][0] += triangle[i - 1][0];
            int last = triangle[i][0] + res[0];
            for (int j = 1; j <= i; j++) {
                int tmp;
                if (j == i) 
                    tmp = triangle[i][j] + res[j - 1];
                else 
                    tmp = triangle[i][j] + min(res[j - 1], res[j]);
                res[j - 1] = last;
                last = tmp;
            }
            res[i] = last;
        }
        
        int min_sum = res[0];
        for (int j = 1; j < m; j++) {
            if (res[j] < min_sum)
                min_sum = res[j];
        }
        
        return min_sum;
    }
};

int main () {
}
