#include <algorithm>
using std::swap;
class Solution {
public:
    void sortColors(int A[], int n) {
        int left = 0, right = n - 1, j = 0;

        while (j <= right) {
            if (A[j] == 0) 
                swap(A[left++], A[j++]);
            else if (A[j] == 2)
                swap(A[right--], A[j]);
            else j++;
        }
        
//        for (int j = 0; j <= right; j++) {
//            if (A[j] == 0) {
//                swap(A[left++], A[j]);
//            } else if (A[j] == 2) {
//                swap(A[right--], A[j--]);
//            }
//        }
    }
};

int main() {
}
