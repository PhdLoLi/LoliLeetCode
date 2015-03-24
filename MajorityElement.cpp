#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::sort;
class Solution {
public:
    int majorityElement(vector<int> &num) {
      sort(num.begin(), num.end());
      return num[num.size() / 2];
    }
};
int main () {
  Solution so;
  vector<int> num({1, 2, 1, 2, 1, 2, 3, 2, 2});
  std::cout << so.majorityElement(num) << std::endl;
}
