#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::sort;
class Solution {
public:
    int majorityElement(vector<int> &num) {
        mergeSort(num, 0, num.size() - 1);
        for (int i = 0; i < num.size(); i++)
          std::cout << num[i] << " " ;
        std::cout << std::endl;
        return num[num.size() / 2];
    }
    
    void mergeSort(vector<int> &num, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(num, low, mid);
        mergeSort(num, mid + 1, high);
        int i = 0, j = 0, k = low;
        vector<int> L(num.begin() + low, num.begin() + mid + 1);
        vector<int> R(num.begin() + mid + 1, num.begin() + high + 1);
        while (i < L.size() && j < R.size()) {
            if (L[i] < R[j]) {
                num[k] = L[i];
                i++;
            } else {
                num[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < L.size()) {
          num[k] = L[i];
          i++;
          k++;
        }
        while (j < R.size()) {
          num[k] = R[j];
          j++;
          k++;
        }
    }
};

int main () {
  Solution so;
  vector<int> num({1, 2, 1, 2, 3, 2, 3, 2, 2});
  std::cout << so.majorityElement(num) << std::endl;
}
