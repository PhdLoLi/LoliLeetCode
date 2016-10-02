#include <vector>
#include <iostream> 
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
      vector<bool> mark(n, true); 
      for (int p = 2; p * p < n; p++) {
        if (!mark[p]) continue;
        int q = p;
        while (p * q < n) {
          mark[p * q] = false;
          q++;
        }
      }
      int counter = 0;
      for (int i = 2; i < n; i++) if (mark[i]) counter++;
      return counter;
    }
};
int main() {
  Solution so;
  so.countPrimes(8963);
}
