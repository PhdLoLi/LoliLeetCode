#include <vector>
using std::vector;
using std::max;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return true;
        int cur = 0, step_max = nums[0];
        while (step_max > 0 && cur < len - 1) {
            cur++;
            step_max = max(step_max - 1, nums[cur]);
        }
        return cur == len - 1? true : false;
    }
};
int main() {
}
