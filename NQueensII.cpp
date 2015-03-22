#include <iostream>
#include <vector>
#include <string>
//using namespace std;
using std::vector;
using std::string;

class Solution {
 public:
  int totalNQueens(int n) {
    vector<string> chessboard(n, string(n, '.')); 
    int sum = 0;
    return tryNQueens(0, chessboard, sum); 
  }

  int tryNQueens(int i, vector<string> &chessboard, int sum) {
    int n = chessboard.size();
    for (int j = 0; j < n; j++) {
      bool placeQ = true;
      int k = 0;
      while (placeQ && k < i) {
        if (chessboard[k][j] == 'Q') placeQ = false;
        k++;  
      }
      k = 1;
      while (placeQ && k <= i && k <= j) {
        if (chessboard[i - k][j - k] == 'Q') placeQ = false;
        k++; 
      }
      k = 1;
      while (placeQ && k <= i && j+k < n) {
        if (chessboard[i - k][j + k] == 'Q') placeQ = false;
        k++;
      }
      if (placeQ) {
        chessboard[i][j] = 'Q';
        if (i == n - 1) {
          sum++;  
          chessboard[i][j] = '.';
          break;
        } else {
          sum = tryNQueens(i + 1, chessboard, sum);
          chessboard[i][j] = '.';
        }
      }
    }
    return sum;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  vector<vector<string> > result;
  int n = 3;
  if (argc > 1)
    n = atoi(argv[1]); 
  std::cout << so.totalNQueens(n) << std::endl;
}
