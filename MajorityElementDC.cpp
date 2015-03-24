#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::sort;
class Solution {
public:
    int majorityElement(vector<int> &num) {
        return findMajority(num, 0, num.size() - 1);
    }
    int findMajority(vector<int> &num, int low, int high) {
        if (low == high) return num[low];
        int mid = (low + high) / 2;
        int left = findMajority(num, low, mid);
        int right = findMajority(num, mid + 1, high);
        if (left == right) return left;
        int counterL = 0, counterR = 0;
        for (int i = low; i <= high; i++) {
            if (num[i] == left) 
                counterL ++;
            else if (num[i] == right)
                counterR ++;
        }
        return counterL >= counterR ? left : right;
    }
};
int main () {
  Solution so;
  vector<int> num({1, 2, 1, 2, 1, 2, 3, 2, 2});
  std::cout << so.majorityElement(num) << std::endl;
}
