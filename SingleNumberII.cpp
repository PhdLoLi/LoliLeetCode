#include <iostream>
class Solution {
public:
    int singleNumber(int A[], int n) {
      int single = 0;
      for (int i = 0; i < sizeof(int) * 8; i++) {
        int count = 0;
        int mask = 1 << i;
        for (int j = 0; j < n; j++) {
          if (A[j] & mask)
            count ++;  
        }
        single += (count % 3) << i;  
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
