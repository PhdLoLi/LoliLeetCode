#include <iostream>
/*
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int len = m, i = 0, j = 0;
        while (j < n && i < len) {
            if (B[j] < A[i]) {
                for (int k = len - 1; k >= i; k--) {
                   A[k + 1] = A[k];
                }
                A[i] = B[j];
                len++;
                j++;
            }
            i++;
        }
        if (j < n) 
            for (int k = j; k < n; k++) {
                A[i] = B[k];
                i++;
            }
    }
};
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int p = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0)
            A[p--] = A[i] > B[j] ? A[i--] : B[j--];
        while (j >= 0) 
            A[p--] = B[j--];
    }
};

int main() {
  Solution so;
  int A[10] = {2};
  int B[] = {1};
  so.merge(A, 1, B, 1);
  for (int i = 0; i < 2; i++) 
    std::cout << A[i] << " ";
}
