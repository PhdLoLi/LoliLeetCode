#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
    string intToRoman(int num) {
      string s;
      vector<vector<string> > dic = {
          {"M", "MM", "MMM"}, 
          {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
          {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
          {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}};
      int digit = 1000;
      for (int i = 0; i < 4; i++) {
        int pos = num/digit;
        if (pos > 0) {
          s.append(dic[i][pos - 1]);
          num %= digit;
        }
        digit /= 10;
      }
      return s;
    }
};
int main(int argc, char* argv[]) {
  Solution so;
  int num = 6;
  if (argc > 1)
    num = atoi(argv[1]);
  std::cout << so.intToRoman(num) << std::endl;
  return 0;
}
