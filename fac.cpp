#include <iostream>
int main(int argv, char *argc[]) {
  int n = std::atoi(argc[1]);
  unsigned long long fac = 1;
  for (int i = 1; i <= n; i++) {
    fac *= i;
  }
  std::cout << fac << std::endl;
  return 1;
}
