#include <vector>
#include <iostream>
using std::vector;
/*
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret(2, -1);
        searchRange(A, 0, n - 1, target, ret, n);
        return ret;
    }
    void searchRange(int A[], int low, int high, int target, vector<int> &ret, int n) {
        if (low > high) return;
        int mid = low + (high - low) / 2;
        if (A[mid] < target) searchRange(A, mid + 1, high, target, ret, n);
        if (A[mid] > target) searchRange(A, low, mid - 1, target, ret, n);
        if (A[mid] == target) {
            if (ret[0] == -1 || ret[0] > mid) ret[0] = mid;
            if (ret[1] < mid) ret[1] = mid;
            if (mid < n - 1 && A[mid + 1] == target)
                searchRange(A, mid + 1, high, target, ret, n);
            if (mid > 0 && A[mid - 1] == target)
                searchRange(A, low, mid - 1, target, ret, n);
        }
    }
};
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret(2, -1);
        int low = 0, high = n - 1; 
        double tar = target - 0.5;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (tar < A[mid]) high = mid - 1;
            else low = mid + 1;
        }
       // std::cout << "low " << low << std::endl;
        if (A[low] != target) return ret;
        ret[0] = low;
        high = n - 1;
        tar = target + 0.5;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (tar < A[mid]) high = mid - 1;
            else low = mid + 1;
        }
        ret[1] = low - 1;
        return ret;
    }
    
};
int main() {
  int A[6] = {0, 0, 0, 1, 2, 3};
  vector<int> B(A, A + 6);
  Solution so;
  vector<int> ret = so.searchRange(A, 6, 0);
} 
