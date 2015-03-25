class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int index = 1;
        for (int i = 1; i < n - 1; i++) {
            if (A[i] != A[i - 1] || A[i] != A[i + 1]) {
                if (index != i)
                    A[index] = A[i];
                index++;
            }
        }
        // last one
        A[index++] = A[n - 1];
        return index;
    }
};

int main() {}
