#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        
      if(n <= 1) return n;
      vector<int> b(n+1);
      b[0] = 1;
      b[1] = 1;
      for (int i = 2; i <= n; i ++)
      {
        for (int j = 0; j < i/2; j ++)
        {
          b[i] += b[j]*b[i-j-1];
        }
        b[i] *=2;
        if(i%2)
          b[i] += b[i/2]*b[i/2];
      }
      return b[n];
    }
};

int main()
{
  int i;
  Solution so;
  for (int i = 0; i < 10 ; i++)
  std::cout <<"N: " << i << " Tree Number: " << so.numTrees(i)<< std::endl;
}
