#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
      if(prices.size()<2) return 0;
      int i, pre_max = 0, all_max = 0, cur_max = 0, diff;

      for(i = 0; i < prices.size()-1 ; i ++)
      {
        diff = prices[i+1] - prices[i];
        cur_max = max(diff, pre_max + diff);
        pre_max = cur_max;
        all_max = max(cur_max, all_max);
      }

      return all_max; 
    }
};
int main()
{
  int v[5] = {2,1,1,3,2};
  std::vector<int> prices(&v[0], &v[5]);
  Solution so;
  std::cout << so.maxProfit(prices) << std::endl;
}
