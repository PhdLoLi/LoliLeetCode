#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> res(nums.size(), 1);
      for (int i = 1; i < res.size(); i++) {
        res[i] = res[i - 1] * nums[i - 1];
      }    
      int back = 1;
      for (int i = res.size() - 2; i >= 0; i--) {
        back *= nums[i + 1];
        res[i] *= back;
      }
      return res;
    }
};
int main() {
  Solution so;
  vector<int> nums = {0, 0};
  so.productExceptSelf(nums);
}
