#include <iostream>
#include <string>
#include <map>
using std::string;
using std::map;
class Solution {
public:
    int romanToInt(string s) {
      int result = 0;
      for (int i = 0; i < s.size(); i++) {
        switch (s[i]) {
          case 'M': {
            result += 1000;
            break;
          } 
          case 'D': {
            result += 500;
            break;
          }
          case 'C': {
            if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M'))
              result -= 100;
            else
              result += 100;
            break;
          }
          case 'L': {
            result += 50;
            break;
          }
          case 'X': {
            if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C'))
              result -= 10;
            else
              result += 10;
            break;
          }
          case 'V': {
            result += 5;
            break;
          }
          case 'I': {
            if (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X'))
              result -= 1;
            else
              result += 1;
          }
        }
      }
      return result;      
    }
};

int main(int argc, char* argv[]) {
  Solution so;
  string s = "IV";
  if (argc > 1)
    s = argv[1];
  std::cout << so.romanToInt(s) << std::endl;
  return 0;
}
