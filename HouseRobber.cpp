#include <vector>
using std::vector;
using std::max;
/* Solution I
class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) return 0;
        int max_all = num[0], max_ending_here = num[0], max_ending_pre = 0;
        for (int i = 1; i < num.size(); i++) {
            int tmp = max_ending_here;
            max_ending_here = max(max_ending_here, max_ending_pre + num[i]);
            max_ending_pre = tmp;
            max_all = max(max_all, max_ending_here);
        }
        return max_all;
    }
};
*/
class Solution {
public:
    int rob(vector<int> &num) {
        int ex = 0, in = 0;
        for (int i = 0; i < num.size(); i++) {
            int tmp = in;
            in = num[i] + ex;
            ex = max(ex, tmp);
        }
        return max(in, ex);
    }
};
int main() {
}
