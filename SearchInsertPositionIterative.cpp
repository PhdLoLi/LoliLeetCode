#include <iostream>

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
      int left = 0, right = n - 1, mid;
      while (left <= right) {
        mid = (left + right) / 2;
        if (target == A[mid]) 
          return mid;
        else if (target < A[mid]) 
          right = mid - 1;
        else  
          left = mid + 1; 
      }
      return left;
    }
};

int main(int argc, char* argv[]) {
  Solution so;
  int A[] = { 0, 1, 4, 9, 11};
  int n = 5;
  int target = 0;
  if (argc > 1)
    target = atoi(argv[1]); 
  std::cout << so.searchInsert(A, n, target) << std::endl;
}
