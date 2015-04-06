#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
using std::string;
using std::to_string;
using std::swap;
/* MY First Solution int ~ string ~ long (detect overflow)
class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int start = x >= 0 ? 0 : 1, end = s.size() - 1;
        std::cout << "start " << start << " end " << end << std::endl;
        while (start < end) 
            swap(s[start++], s[end--]);
        std::cout << "string  " << s << std::endl;
        std::cout << "INT_MAX " << INT_MAX << std::endl;
        std::cout << "INT_MIN " << INT_MIN << std::endl;
        std::cout << "LONG_MAX " << LONG_MAX << std::endl;
        std::cout << "LONG_MIN " << LONG_MIN << std::endl;
        std::cout << "LONG LONG_MAX " << LLONG_MAX << std::endl;
        std::cout << "LONG LONG_MIN " << LLONG_MIN << std::endl;
        std::cout << "before return " << stol(s) << std::endl;
        long res = stol(s);
        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};
*/
/* Solution II every digit reverse  Overflow has the same
class Solution {
public:
    int reverse(int x) {
        int num = abs(x);
        long res = 0;
        while (num != 0) {
            int digit = num % 10;
            num /= 10;
            res = res * 10 + digit;
        }
        if (x < 0) res = -res;
        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};
*/
/*Solution III No abs different Overflow & Underflow detection*/
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            x /= 10;
            //if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
        }
        return res ;
    }
};

int main (int argc, char *argv[]) {
  int num = 0;
  if (argc > 1)
    num = atoi(argv[1]);
  Solution so;
  std::cout << "num input " << num << std::endl;
  std::cout <<  so.reverse(num) << std::endl;
}
