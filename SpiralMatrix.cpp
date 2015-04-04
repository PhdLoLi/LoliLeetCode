#include <vector>
#include <iostream>
using namespace std;
/* V0
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
      vector<int> result;
      int m, n, startC, endC, startR, endR, i, j;
      m = matrix.size();
      if(m == 0)
        return result;
      n = matrix[0].size();
      if(n == 0)
        return result;

      startR = 0;
      startC = 0;
      endR = m - 1;
      endC = n - 1;
      while (1)
      {
        for(j = startC; j <= endC; j++)
          result.push_back(matrix[startR][j]);
        startR++;
        if(startR>endR) 
          break;

        for(i = startR; i <= endR; i++)
          result.push_back(matrix[i][endC]);
        endC --;
        if(startC>endC)
          break;

        for(j = endC; j>=startC; j--)
          result.push_back(matrix[endR][j]);
        endR --;
        if(startR>endR)
          break;

        for(i = endR; i>=startR; i--)
          result.push_back(matrix[i][startC]);
        startC ++;
        if(startC>endC)
          break;
      }
      return result;  
    }
};
*/
/* 4.03 Rewrite */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m == 0) return res;
        int n = matrix[0].size();
        for (int i = 0; i < min(m, n) / 2; i++) {
            int endCol = n - 1 - i;
            int endRow = m - 1 - i;
            for (int j = i; j < endCol; j++)
                res.push_back(matrix[i][j]);
            for (int j = i; j < endRow; j++)
                res.push_back(matrix[j][endCol]);
            for (int j = endCol; j > i; j--)
                res.push_back(matrix[endRow][j]);
            for (int j = endRow; j > i; j--)
                res.push_back(matrix[j][i]);
        }
        if (m < n && m % 2 == 1) 
            for (int j = m/2; j <= n - 1 - m/2; j++)
                res.push_back(matrix[m/2][j]);
        if (n <= m && n % 2 == 1)
            for (int j = n/2; j <= m - 1 - n/2; j++)
                res.push_back(matrix[j][n/2]);
        return res;  
    }
};
int main(int argc, char *argv[])
{
  vector<int> result;
  int m, n, i, j;
  m = 3;
  n = 3;
  if(argc > 2)
  {
    m = atoi(argv[1]);
    n = atoi(argv[2]);
  }else if(argc == 2)
  {
    m = atoi(argv[1]);
    n = atoi(argv[1]);
  }
 
  vector<vector<int> > matrix(m, (vector<int>(n,0)));
  for(i=0; i<m; i++)
  {
    for(j=0; j<n; j++)
    {
      matrix[i][j] = n*i + j +1;
      cout << "  " << matrix[i][j];
    }
    cout << endl;
  }

  Solution so;
  result = so.spiralOrder(matrix);
  cout << "Result: Matrix Size  " << result.size() << endl;
  for(i = 0; i< result.size(); i++)
    cout << " " << result[i];
  cout << endl;
//  matrix = [[ 1, 2, 3 ], [ 4, 5, 6 ],[ 7, 8, 9 ]];
  return 0;
}
