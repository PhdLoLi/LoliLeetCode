#include <iostream>
class Solution {
public:
    int singleNumber(int A[], int n) {
      int single = 0, count[sizeof(int) * 8] = {0};
      for (int i = 0; i < n; i++)
      {
        int tmp = A[i];
        for (int j = 0; j < sizeof(int) * 8; j++) {
          count[j] += tmp & 0x01;
          tmp >>= 1;
        } 
      }
      for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
//        std::cout << count[i] % 3 << std::endl;
        single = single << 1 | count[i] % 3;  
      } 
      return single;
    }
};
int main()
{
  Solution so; 
  int A[7] = { 0,1,0,1,0,1,99 };
  std::cout << so.singleNumber(A, 7) << std::endl; 
}
