#include <iostream>
#include <vector>
#include <string>
//using namespace std;
using std::vector;
using std::string;

class Solution {
 public:
  vector<vector<string> > result; 

  vector<vector<string> > solveNQueens(int n) {
    vector<string> chessboard(n, string(n, '.')); 
    tryNQueens(0, chessboard); 
    return result;
  }

  void tryNQueens(int i, vector<string> &chessboard) {
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
//          vector<string> solution(chessboard); 
//          result.push_back(solution);
          result.push_back(chessboard);
          chessboard[i][j] = '.';
          break;
        } else {
          tryNQueens(i + 1, chessboard);
          chessboard[i][j] = '.';
        }
      }
    }
  }
};


  void printQueens(vector<vector<string> > &result) {
    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++)
        std::cout << result[i][j] << std::endl;
      std::cout << std::endl;
    }
  }


int main(int argc, char* argv[]) {
  Solution so;
  vector<vector<string> > result;
  int n = 3;
  if (argc > 1)
    n = atoi(argv[1]); 
  result = so.solveNQueens(n);
  printQueens(result);
}
