/* V0
class Solution {
public:
    bool search(int A[], int n, int target) {
        return bsSearch(A, 0, n - 1, target);   
    }
    bool bsSearch(int A[], int l, int h, int target) {
        if (l > h) return false;
        if (l == h) return target == A[l];
        int m = (l + h) / 2;
        if (target == A[m]) return true;
        if (target == A[h]) return true;
        if (target == A[l]) return true;
        if (A[m] > A[h]) {
            if (target > A[m]) return bsSearch(A, m + 1, h - 1, target);
            else return target < A[h] ? 
                        bsSearch(A, l, m - 1, target) || bsSearch(A, m + 1, h - 1, target) : bsSearch(A, l, m - 1, target);
        } else if (A[m] < A[h]) {
            if (target < A[m]) return bsSearch(A, l, m - 1, target);
            else return target > A[l] ? 
                        bsSearch(A, m + 1, h, target) || bsSearch(A, l + 1, m - 1, target) : bsSearch(A, m + 1, h, target);
        } else return bsSearch(A, m + 1, h - 1, target) || bsSearch(A, l, m - 1, target);
    }
};
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        return bsSearch(A, 0, n - 1, target);   
    }
    bool bsSearch(int A[], int l, int h, int target) {
        if (l > h) return false;
        int m = (l + h) / 2;
        if (target == A[m]) return true;
        if (A[m] > A[h]) {
            return target >= A[l] && target < A[m] ? bsSearch(A, l, m - 1, target) : bsSearch(A, m + 1, h, target);
        } 
        if (A[m] < A[h]) {
            return target > A[m] && target <= A[h] ? bsSearch(A, m + 1, h, target) : bsSearch(A, l, m - 1, target);
        }
        return bsSearch(A, m + 1, h - 1, target) || bsSearch(A, l, m - 1, target);
    }
};

int main() {}
