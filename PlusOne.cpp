#include <vector>
using std::vector;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int i = digits.size() - 1;
        for (; i >= 0 && digits[i] == 9; i--) digits[i] = 0;
        if (i >= 0) digits[i]++;
        else digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main() {
}
