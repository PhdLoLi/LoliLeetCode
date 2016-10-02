#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int i = 0, j = numbers.size() - 1;
      while (i < j) {
        if (numbers[i] + numbers[j] > target) j--;
        else if (numbers[i] + numbers[j] < target) j++;
        else return vector<int>({i, j}); 
      }
      return vector<int>();
    }
};
int main() {
  Solution so;
}
