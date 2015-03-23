#include <iostream>
#include <algorithm>
using std::max;
class Solution {
public:
    int maxSubArray(int A[], int n) {
      if (n == 0) return 0;
      int max_so_far = A[0], max_ending_here = A[0];
      for (int i = 1; i < n; i++) {
        max_ending_here = max(max_ending_here + A[i], A[i]);
        if (max_ending_here > max_so_far) max_so_far = max_ending_here;
      }
      return max_so_far;
    }
};
int main() {
  Solution so;
  int A[] = {-2, -1, -3, -4, -1, -1, -2, -1, -5, -4};
  std::cout << so.maxSubArray(A, 10) << std::endl;
}
