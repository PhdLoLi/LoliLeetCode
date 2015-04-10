#include <vector>
#include <iostream>
using std::vector;
/* Solution I 
class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combine(int n, int k) {
        vector<int> sol;
        combine(n, k, 1, sol);
        return res;
    }
    void combine(int n, int k, int start, vector<int> &sol) {
                  for (vector<int>::iterator it = sol.begin(); it < sol.end(); it++)
            std::cout << *it;
            std::cout << std::endl;
      if (sol.size() > k) std::cout << "SHOULD NOT" << std::endl;
        if (sol.size() == k) {
            res.push_back(sol);
            std::cout << "result ";
            for (vector<int>::iterator it = sol.begin(); it < sol.end(); it++)
            std::cout << *it;
            std::cout << std::endl;
            return;
        }
        for (int i = start; i <= n; i++) {
          std::cout << "i " << i << std::endl;
                sol.push_back(i);
                std::cout << "before " << std::endl;
                combine(n, k, i + 1, sol);
                std::cout << "end " << std::endl;
                sol.pop_back();
        }
    }
};
*/
/* Solution II */ 
class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int> > combine(int n, int k) {
        vector<int> sol;
        combine(n, k, 1, sol);
        return res;
    }
    void combine(int n, int k, int start, vector<int> &sol) {
        if (k == 0) {
            res.push_back(sol);
            return;
        }
        for (int i = start; i <= n - k + 1; i++) {
                sol.push_back(i);
                combine(n, k - 1, i + 1, sol);
                sol.pop_back();
        }
    }
};
int main() {
  int n = 5, k = 3;
  Solution so;
  so.combine(n, k);
}
