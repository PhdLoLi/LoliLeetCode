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
      string dic = "MDCLXVI";
      int digit = 1000;
      for (int i = 0; i < 4; i++) {
        int pos = num / digit;
        if (pos == 4) {
          s.push_back(dic[2 * i]);
          s.push_back(dic[2 * i - 1]);
        } else if (pos == 9) {
          s.push_back(dic[2 * i]);
          s.push_back(dic[2 * i - 2]);
        } else {
          if (pos >= 5) { 
            s.push_back(dic[2 * i -1]);
            pos -= 5;
          }
          for (int j = 0; j < pos; j++)
            s.push_back(dic[2 * i]);
        }
        num %= digit;
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
