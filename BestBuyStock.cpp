#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
      if(prices.size()<2) return 0;
      int i, max_whole = 0, cur = 0;
      vector<int> diff(prices.size()-1);
      for(i = 0; i < prices.size()-1; i ++)
      {
        diff[i] = prices[i+1] - prices[i];
    
        cur = max(cur+diff[i], 0);
        max_whole = max(cur, max_whole);
      }

      return max_whole; 
    }
};
int main()
{
  int v[4] = {2,4,7,1};
  std::vector<int> prices(&v[0], &v[3]);
  Solution so;
  std::cout << so.maxProfit(prices) << std::endl;
}
