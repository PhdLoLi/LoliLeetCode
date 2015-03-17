#include <vector>
#include <iostream>
using namespace std;
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
      while (startR<=endR && startC<=endC)
      {
        if(startR == endR)
        {
          for(j = startC; j <= endC; j++)
            result.push_back(matrix[startR][j]);
          break;
        }
        if(startC == endC)
        {
          for(i = startR; i <= endR; i++)
            result.push_back(matrix[i][endC]);
          break;
        }
        for(j = startC; j <= endC; j++)
          result.push_back(matrix[startR][j]);
        startR++;

        for(i = startR; i <= endR; i++)
          result.push_back(matrix[i][endC]);
        endC --;

        for(j = endC; j>=startC; j--)
          result.push_back(matrix[endR][j]);
        endR --;

        for(i = endR; i>=startR; i--)
          result.push_back(matrix[i][startC]);
        startC ++;
        
      }
      return result;  
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
