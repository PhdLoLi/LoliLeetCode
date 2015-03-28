/* V0
class Solution {
public:
    int search(int A[], int n, int target) {
        return bsSearch(A, 0, n - 1, target);   
    }
    int bsSearch(int A[], int l, int h, int target) {
        if (l > h) return -1;
        if (l == h) return target == A[l] ? l : -1;
        int m = (l + h) / 2;
        if (target == A[m]) return m;
        if (target > A[m]) {
            if (A[m] > A[h]) return bsSearch(A, m + 1, h - 1, target);
            else {
                if (target == A[h]) return h;
                else {
                    int left = bsSearch(A, l, m - 1, target);
                    return (left < 0 && target < A[h]) ? bsSearch(A, m + 1, h - 1, target) : left;
                }
            }
        }else {
            if (A[m] < A[h]) return bsSearch(A, l, m - 1, target);
            else {
                if (target == A[l]) return l;
                else { 
                    int right = bsSearch(A, m + 1, h, target);
                    return (right < 0 && target > A[l]) ? bsSearch(A, l + 1, m - 1, target) : right;
                }
            }
        }
    }
};
*/

/* V1
class Solution {
public:
    int search(int A[], int n, int target) {
        return bsSearch(A, 0, n - 1, target);   
    }
    int bsSearch(int A[], int l, int h, int target) {
        if (l > h) return -1;
        if (l == h) return target == A[l] ? l : -1;
        int m = (l + h) / 2;
        if (target == A[m]) return m;
        if (target == A[h]) return h;
        if (target == A[l]) return l;
        if (A[m] > A[h]) {
            if (target > A[m]) return bsSearch(A, m + 1, h - 1, target);
            else {
                int right = bsSearch(A, m + 1, h, target);
                return (right < 0 && target > A[l]) ? bsSearch(A, l + 1, m - 1, target) : right;
            }
        } else {
            if (target < A[m]) return bsSearch(A, l, m - 1, target);
            else {
                int left = bsSearch(A, l, m - 1, target);
                return (left < 0 && target < A[h]) ? bsSearch(A, m + 1, h - 1, target) : left;
            }
        }
    }
};
*/

/* V2
class Solution {
public:
    int search(int A[], int n, int target) {
        return bsSearch(A, 0, n - 1, target);   
    }
    int bsSearch(int A[], int l, int h, int target) {
        if (l > h) return -1;
        int m = (l + h) / 2;
        if (target == A[m]) return m;
        if (A[m] > A[h]) {
            return target >= A[l] && target < A[m] ? bsSearch(A, l, m - 1, target) : bsSearch(A, m + 1, h, target);
        } else {
            return target > A[m] && target <= A[h] ? bsSearch(A, m + 1, h, target) : bsSearch(A, l, m - 1, target);
        }
    }
};
*/

/* V3 */
class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (target == A[m]) return m;
            if (A[m] > A[h]) {
                if (target >= A[l] && target < A[m]) h = m - 1;
                else l = m + 1;
            } else {
                if (target > A[m] && target <= A[h]) l = m + 1;
                else h = m - 1;
            }
        }
        return -1;
    }
};

int main() {}
