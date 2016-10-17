#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
  vector<vector<int>> res;
  void comSum(vector<int>& can, vector<int>& tmp, int target, int pos) {
    if (target == 0) { res.push_back(tmp);  return;} 
    for (int i = pos; i < can.size(); i++) {
      if (target >= can[i]) {
      tmp.push_back(can[i]);
      comSum(can, tmp, target - can[i], i + 1); 
      tmp.pop_back();
      } else break;
      while (i + 1 < can.size() && can[i] == can[i + 1]) i++;
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> tmp;
    comSum(candidates, tmp, target, 0);
    return res;    
  }
};


int main() {
  Solution so;

}
