#include <vector>
#include <iostream>
using std::vector;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        ret.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            int left = 1;
            for (int j = 1; j < i; j++) {
                int tmp = ret[j];
                ret[j] += left;
                left = tmp;
            }
            ret.push_back(1);
        } 
        return ret;
    }
};
int main() {
  Solution so;
  so.getRow(3);
}
