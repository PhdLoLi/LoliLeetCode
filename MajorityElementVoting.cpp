#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::sort;
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int counter = 1, candidate = num[0];
        for (int i = 1; i < num.size(); i++) {
            if (counter == 0) {
                candidate = num[i];
                counter = 1;
                } else { 
                if (num[i] == candidate) 
                    counter++;
                else {
                    counter--;
                }
            }
        }
        return candidate;
    }
};
int main () {
  Solution so;
  vector<int> num({1, 2, 1, 2, 1, 2, 3, 2, 2});
  std::cout << so.majorityElement(num) << std::endl;
}
