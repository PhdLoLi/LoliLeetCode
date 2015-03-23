#include <algorithm>
using std::max;
using std::min;
class Solution {
public:
    int maxProduct(int A[], int n) {
      if (n == 0) return 0;
      int max_ending_here, min_ending_here ,max_so_far;    
      max_ending_here = min_ending_here = max_so_far = A[0];    
      for (int i = 1; i < n; i++) {
//        if (A[i] > 0) {  
//          max_ending_here = max(max_ending_here * A[i], A[i]);
//          min_ending_here = min(min_ending_here * A[i], A[i]);
//        }
//        else { 
//          int max_tmp = max_ending_here;
//          max_ending_here = max(min_ending_here * A[i], A[i]);
//          min_ending_here = min(max_tmp * A[i], A[i]);
//        }
        int max_tmp = max_ending_here;
        max_ending_here = max(max(max_ending_here * A[i], min_ending_here * A[i]), A[i]);
        min_ending_here = min(min(max_tmp * A[i], min_ending_here * A[i]), A[i]);
        if (max_ending_here > max_so_far) max_so_far = max_ending_here;
      }
      return max_so_far;
    }
};
int main() {
}
