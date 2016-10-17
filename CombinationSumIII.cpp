#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
  vector<vector<int>> res;
  void comSum(int k, int n, int cur, vector<int> &tmp) {
    if (k== 0 && n == 0) { res.push_back(tmp); return; } 
    for (int i = cur; i <= 9; i++) {
      if (n >= i && k > 0) {
        tmp.push_back(i);
        comSum(k - 1, n - i, i + 1, tmp);
        tmp.pop_back();  
      } else break;
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> tmp;
    comSum(k, n, 1, tmp);
    return res;
  }
};
int main() {
  Solution so;
}
