#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
  static bool big_than(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
  } 

  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> ht;
    for (int i = 0; i < nums.size(); i++) {
      ht[nums[i]]++;
    }
    vector<pair<int, int>> v;
    for (auto a : ht) {
      v.emplace_back(make_pair(a.second, a.first));
    }    
    make_heap(v.begin(), v.end(), big_than);
    vector<int> res;
    for (int i = 0; i < k; i++) {
      pop_heap(v.begin(), v.end() - i, big_than);
      res.push_back(v[v.size() - i - 1].second);
    }

    return res;
  }
};
int main() {
  vector<int> nums = {1,1,1,2,2,3};
  int k = 2;
  Solution so;
  so.topKFrequent(nums, 2);
}
