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

      for (int i = 0; i < num / 1000; i++) {
        s.push_back('M');
      }
      num %= 1000;

      switch (num / 100) {
        case 0 : break;
        case 1 : {
          s.append("C");
          break;
        }
        case 2 : {
          s.append("CC");
          break;
        }
        case 3 : {
          s.append("CCC");
          break;
        }
        case 4 : {
          s.append("CD");
          break;
        }
        case 5 : {
          s.append("D");
          break;
        }
        case 6 : {
          s.append("DC");
          break;
        }
        case 7 : {
          s.append("DCC");
          break;
        }
        case 8 : {
          s.append("DCCC");
          break;
        }
        case 9 : {
          s.append("CM");
          break;
        }
      } 
      num %= 100;

      switch (num / 10) {
        case 0 : break;
        case 1 : {
          s.append("X");
          break;
        }
        case 2 : {
          s.append("XX");
          break;
        }
        case 3 : {
          s.append("XXX");
          break;
        }
        case 4 : {
          s.append("XL");
          break;
        }
        case 5 : {
          s.append("L");
          break;
        }
        case 6 : {
          s.append("LX");
          break;
        }
        case 7 : {
          s.append("LXX");
          break;
        }
        case 8 : {
          s.append("LXXX");
          break;
        }
        case 9 : {
          s.append("XC");
          break;
        }
      } 
      num %= 10;

      switch (num) {
        case 0 : break;
        case 1 : {
          s.append("I");
          break;
        }
        case 2 : {
          s.append("II");
          break;
        }
        case 3 : {
          s.append("III");
          break;
        }
        case 4 : {
          s.append("IV");
          break;
        }
        case 5 : {
          s.append("V");
          break;
        }
        case 6 : {
          s.append("VI");
          break;
        }
        case 7 : {
          s.append("VII");
          break;
        }
        case 8 : {
          s.append("VIII");
          break;
        }
        case 9 : {
          s.append("IX");
          break;
        }
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
