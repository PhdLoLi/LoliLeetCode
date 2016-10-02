#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> res;
    res.push_back(0);
    while (res.size() <= num) {
      int size = res.size();
      for (int j = 0; j < size && j + size <= num; j++) {
        res.push_back(res[j] + 1);
      }
    }
    return res;
  }
};
int main() {
  Solution so;
  so.countBits(10);
}
