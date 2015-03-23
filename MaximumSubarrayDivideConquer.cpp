#include <iostream>
#include <algorithm>
using std::max;
class Solution {
public:
    int maxSubArray(int A[], int n) {
      if (n == 0) return 0;
      return maxSubArrayDC(A, 0, n - 1);  
    }
    int maxSubArrayDC(int A[], int low, int high) {
      if (low == high) return A[low];
      int mid = (low + high) / 2, max_mid = A[mid], sum = A[mid];

      for (int i = mid - 1; i >= low; i--) {
        sum += A[i];
        if(sum > max_mid) max_mid = sum;
      }
      sum = max_mid;
      for (int i = mid + 1; i <= high; i++) {
        sum += A[i]; 
        if(sum > max_mid) max_mid = sum;
      }
      
      if (low <= mid - 1) {
        int max_low = maxSubArrayDC(A, low, mid - 1);
        if (max_low > max_mid) max_mid = max_low;
      }
      int max_high = maxSubArrayDC(A, mid + 1, high);
      return max_mid > max_high ? max_mid : max_high; 
    }
};
int main() {
  Solution so;
  int A[] = {-2, -1, -3, -4, 1, -1, 2, 1, -5, -4};
  std::cout << so.maxSubArray(A, 10) << std::endl;
}
