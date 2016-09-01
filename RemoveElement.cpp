#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n <= 0) return n;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == elem) {
                count++;
            } else {
                if (count > 0) {
                    A[i - count] = A[i];
                }
            }
        }
        return n - count;
    }

    int removeElementTwoPointers(int A[], int n, int elem) { //Using this one!!
        if (n <= 0) return n;
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != elem) {
                if (index != i)
                    A[index] = A[i];
                index++;
            }
        }
        return index;
    }

    int removeElementStartEnd(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            if (nums[start] == val) {
                int tmp = nums[end];
                nums[end] = nums[start];
                nums[start] = tmp;
                end--;
            } else start++;
        }
        return end + 1;
    }
};
int main() {}
