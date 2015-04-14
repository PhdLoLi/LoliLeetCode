#include <stdlib.h>
#include <math.h>
#include <iostream>
/*
class Solution {
public:
    bool isPalindrome(int x) {
        //x = abs(x);
        if (x < 0) return false;
        if (x < 10) return true;
        int digit = 0;
        for (int num = abs(x); num >= 10; num /= 10) digit++;
        int start = digit, end = 0, base = pow(10, digit);
        std::cout << "start " << start << std::endl;
        std::cout << "end " << end << std::endl;
        std::cout << "base " << base << std::endl;
        while (start > end) {
            int low = x % 10;
            int high =  x / base;
            std::cout << "start " << start << " end " << end << std::endl;
            std::cout << "low " << low << " high " << high << std::endl;
            if (low != high) return false;
            x %= base;
            x /= 10;
            base /= 100;
            end++;
            start--;
        }
        return true;
    }
};
*/
/* Reverse & Overflow 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int reverse = 0, y = x;
        while (x) {
            if (reverse > INT_MAX / 10) return false;
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse == y;
    }
};
*/

class Solution {
public:
    bool isPalindrome(int x) {
        //x = abs(x);
        if (x < 0) return false;
        if (x < 10) return true;
        int base = 1;
        for (int num = x; num >= 10; num /= 10) base *= 10;
        while (x) {
            if (x % 10 != x / base) return false;
            x %= base;
            x /= 10;
            base /= 100;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    int n = std::atoi(argv[1]);
    Solution so;
    std::cout << so.isPalindrome(n) << std::endl;
    return 0;
}
