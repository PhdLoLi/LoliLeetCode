#include <iostream>

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
      int left = 0, right = n - 1, mid = (n - 1) / 2; 
      while (left <= right) {
        if (left == right) {
          return target <= A[left] ? left : left + 1; 
        }
        mid = (left + right) / 2;
        if (target == A[mid]) {
          return mid;
        } else if (target < A[mid]) {
          if (left == mid) 
            return left;
          right = mid - 1;
        } else 
         left = mid + 1; 
      }
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
