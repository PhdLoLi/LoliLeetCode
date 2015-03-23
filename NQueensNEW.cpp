#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using std::vector;
using std::string;
using std::abs;

class Solution {
 public:
  vector<vector<string> > result;

  vector<vector<string> > solveNQueens(int n) {
    vector<int> record;
    vector<string> chessboard;
    tryNQueens(n, 0, record, chessboard); 
    return result;
  }

  void tryNQueens(int n, int i, vector<int> &record, vector<string> &chessboard) {
    if (i == n) {
      result.push_back(chessboard);
      return;
    }
    for (int j = 0; j < n; j++) {
      if (validPosition(i, j, record)) {
        string s(n, '.');
        s[j] = 'Q';
        chessboard.push_back(s);
        record.push_back(j);
        tryNQueens(n, i + 1, record, chessboard);
        record.pop_back();
        chessboard.pop_back();
      }
    }
  }

  bool validPosition(int i, int j, vector<int> &record) {
    for (int k = 0; k < record.size(); k++) {
      if (record[k] == j || abs(i - k) == abs(j - record[k]))
        return false;
    } 
    return true;
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
