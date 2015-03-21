#include <iostream>

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
      return bianrySearch(A, 0, n - 1, target);
    }

    int bianrySearch(int A[], int left, int right, int target) {
      if (left == right) {
        return target <= A[left] ? left : left + 1; 
      }
      int mid = (left + right) / 2;
      if (target == A[mid]) {
        return mid;
      } else if (target < A[mid]) {
          return left == mid ? left : bianrySearch(A, left, mid - 1, target);
      } else {
        return bianrySearch(A, mid + 1, right, target);
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
