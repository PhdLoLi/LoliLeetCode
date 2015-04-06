#include <iostream>
#include <bitset>
#include <algorithm>
using std::bitset;
using std::swap;
/* Solution I
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; i++) {
            int tmp = n & 0x01;
            ret = (ret << 1) + tmp;
            std::cout << "i " << i << " tmp" << tmp << " ret " << ret << " n " << n << std::endl;
            n >>= 1;
        }
        return ret;
    }
};
*/
/* Solution I'
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int counter = 0;
        while (n != 0) {
            int tmp = n & 0x01;
            ret = (ret << 1) | tmp;
            n >>= 1;
            counter++;
        }
        ret <<= (32 - counter);
        return ret;
    }
};
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bs(n);
        int start = 0, end = 31;
        while (start < end) {
            int tmp = bs[start];
            bs[start] = bs[end];
            bs[end] = tmp;
            start++;
            end--;
          //  swap(bs[start++], bs[end--]);
        }
        return bs.to_ulong();
    }
};
int main (int argc, char *argv[]) {
  int num = 0;
  if (argc > 1)
    num = atoi(argv[1]);
  Solution so;
  std::cout << "num input " << num << std::endl;
  std::cout <<  so.reverseBits(num) << std::endl;
}
