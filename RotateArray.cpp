#include <vector>
#include <algorithm>
using std::vector;
using std::min;
/* Space O(1) Time O(n) */
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n <= 0 || k <= 0 || k % n == 0) return;
        k %= n;
        int times = 1;
        if (n % min(n - k, k) == 0) times = min(n - k, k);
        for (int start = 0; start < times; start++) {
            int i = start;
            int tmp = nums[start];
            do {
                int index = (i + k) % n;
                int tmp2 = nums[index];
                nums[index] = tmp;
                tmp = tmp2;
                i = index;
            } while(i != start);
        }
    }
};
/* Three Times Reverse 
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n <= 0 || k <= 0 || k % n == 0) return;
        k %= n;
        reverseRotate(nums, 0, n - k - 1);
        reverseRotate(nums, n - k, n - 1);
        reverseRotate(nums, 0, n - 1);
    }
    void reverseRotate(int nums[], int start, int end) {
        while (start < end)
            swap(nums[start++], nums[end--]);
    }
};
*/

/* Space O(n) Time O(n)
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n <= 0 || k <= 0 || k % n == 0) return;
        k %= n;
        vector<int> new_nums(nums, nums + n);
        int i = 0;
        for (; i < k; i++)
            nums[i] = new_nums[i + n - k];
        for (; i < n; i++)
            nums[i] = new_nums[i - k];
    }
};
*/
int main() {
}
