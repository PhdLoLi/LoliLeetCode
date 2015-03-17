#include <iostream>
class Solution {
public:
    int singleNumber(int A[], int n) {
      int single, i;
      single = 0;

      for(i=0; i+1<n; i=i+2)
      {
        single ^= A[i]^A[i+1];
      }   
      single ^= A[n-1];
      return single;
    }
};
int main()
{
  Solution so; 
  int A[5] = {19999};
  std::cout << so.singleNumber(A, 5) << std::endl; 
}
