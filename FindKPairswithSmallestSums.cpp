#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
 public:
  vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> res;
    int m = nums1.size(), n = nums2.size();
    if (!k || !m || !n) return res;
    k = min(k, m * n);
    
    auto cmp = [&nums1,&nums2](pair<int, int> a ,pair<int, int> b){
      return nums1[a.first] + nums2[a.second ]>= nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>,vector<pair<int, int>>,decltype(cmp)> q(cmp);
    q.emplace(0, 0);

    while (k-- > 0) {
      pair<int, int> p = q.top();
      q.pop();
      res.emplace_back(nums1[p.first], nums2[p.second]);
      if (p.first + 1 < m) q.emplace(p.first + 1, p.second);
      if (p.first == 0 && p.second + 1 < n) q.emplace(0, p.second + 1);
      if (p.first + 1 == m && p.second + 1 == n) break;
    }
    return res;

  }
};
int main() {
  Solution so;
}
