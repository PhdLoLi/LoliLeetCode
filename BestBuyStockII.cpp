#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
      if(prices.size()<2) return 0;
      int i, max_whole = 0, diff;
      for(i = 0; i < prices.size()-1; i++) 
      {
        diff = prices[i+1] - prices[i];
        if(diff > 0)
    
        max_whole += diff;
      }

      return max_whole; 
    }
};
int main()
{
  int v[5] = {2,8,7,1,3};
  std::vector<int> prices(&v[0], &v[5]);
  Solution so;
  std::cout << so.maxProfit(prices) << std::endl;
}
