#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::sort;
class Solution {
public:
    int majorityElement(vector<int> &num) {
        quickSort(num, 0, num.size() - 1);
        for (int i = 0; i < num.size(); i++)
          std::cout << num[i] << " " ;
        std::cout << std::endl;
        return num[num.size() / 2];
    }
    
    void quickSort(vector<int> &num, int low, int high) {
      if (low >= high) return;
      int p = partition(num, low, high);
      quickSort(num, low, p - 1);
      quickSort(num, p + 1, high);
    }
    int partition(vector<int> &num, int low, int high) {
      int i = low - 1;
      for (int j = low; j < high; j++) {
        if (num[j] <= num[high]) {
          int tmp = num[++i];
          num[i] = num[j];
          num[j] = tmp;
        }
      }
      int tmp = num[++i];
      num[i] = num[high];
      num[high] = tmp;
      return i;
    }
};

int main () {
  Solution so;
  vector<int> num({1, 2, 1, 2, 3, 2, 3, 2, 2});
  std::cout << so.majorityElement(num) << std::endl;
}
