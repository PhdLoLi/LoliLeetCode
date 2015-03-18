#include <iostream>
#include <string>
#include <cctype>
#include <math.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
      int sum = 0, cur;
      for(int i = 0; i < s.length(); i++)
      {
        cur = s[i] - 'A' + 1;
        sum = sum*26 + cur;
      }
      return sum;
    }
};
int main(int argc, char * argv[])
{
  Solution so;
  string s;
  if(argc > 1)
    s = argv[1];
  else
    s = "A";

  cout << so.titleToNumber(s) << endl;
}
