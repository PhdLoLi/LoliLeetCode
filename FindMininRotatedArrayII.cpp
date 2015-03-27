#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int findMin(vector<int> &num) {
        return bsMin(num, 0 , num.size() - 1);
    }
    int bsMin(vector<int> &num, int low, int high) {
        if(low >= high || num[low] < num[high]) return num[low];
        int mid = (low + high) / 2;
        if (num[mid] < num[high])
            return bsMin(num, low, mid);
        else if (num[mid] == num[high]) {
            int left = bsMin(num, low, mid - 1);
            int right = bsMin(num, mid + 1, high - 1);
            return left < right ? left : right; 
        } else 
            return bsMin(num, mid + 1, high);
    }
};

int main() {
  Solution so;
  vector<int> num = {3,3,3,1};
  std::cout << so.findMin(num) << std::endl;
}
