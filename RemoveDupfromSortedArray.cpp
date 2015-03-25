class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;
        int index = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] != A[i - 1]) {
                if (index != i) 
                    A[index] = A[i];
                index++;
            }
        }
        return index;
    }
};

int main() {}
