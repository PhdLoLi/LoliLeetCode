#include <iostream>
using namespace std;
int findNthDigit(int n) {
    int sum = 9, d = 1, base = 1;
    while ((long long)9 * base * d - n < 0) {
        n -= 9 * base * d++;
        base *= 10;
        printf("n: %d, base: %d, d: %d\n", n, base ,d);
    }
    n--;
    int num = n / d + base;
    printf("num: %d, base: %d, d: %d, n mod d: %d\n", num, base, d, n % d);
    for (int i = 1; i < d - n % d; i++) {
        num /= 10;
    }
    cout << "result " << num % 10 << endl;
    return num % 10;
}

int main() {
  findNthDigit(1000000000);
}
