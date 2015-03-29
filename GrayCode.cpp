#include <vector>
using std::vector;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        int base = 1;
        gray.push_back(0);
        for (int i = 1 ; i <= n; i++) {
            for (int j = gray.size() - 1; j >= 0; j--) {
                gray.push_back(gray[j] + base);
            }
            base <<= 1;
        }
        return gray;
    }
};
int main() {
}
