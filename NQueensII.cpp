#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
//using namespace std;
using std::vector;
using std::string;
using std::abs;

class Solution {
 public:
  int totalNQueens(int n) {
    vector<int> record;
    int sum = 0;
    tryNQueens(n, 0, record, sum); 
    return sum;
  }

  void tryNQueens(int n, int i, vector<int> &record, int &sum) {
    if (i == n) {
      sum++;
      return;
    }
    for (int j = 0; j < n; j++) {
      if (validPosition(i, j, record)) {
        record.push_back(j);
        tryNQueens(n, i + 1, record, sum);
        record.pop_back();
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

int main(int argc, char* argv[]) {
  Solution so;
  vector<vector<string> > result;
  int n = 3;
  if (argc > 1)
    n = atoi(argv[1]); 
  std::cout << so.totalNQueens(n) << std::endl;
}
