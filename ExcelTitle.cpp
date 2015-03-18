#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
      string s = "";
      char cur_char;
      int cur;
      while(n > 0)
      {
        cur = n%26;
        if(cur == 0) cur = 26;
        cur_char = 'A' + cur - 1; 
        s.insert(0, 1, cur_char);
        n = (n - cur)/26;
      }
      return s; 
    }
};
int main(int argc, char *argv[])
{
  int n;
  Solution so;
  if(argc > 1)
    n = atoi(argv[1]);
  else
    n = 2;
  cout << so.convertToTitle(n) << endl;
}
