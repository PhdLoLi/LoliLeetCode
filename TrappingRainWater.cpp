#include <stack>
#include <vector>
using std::vector;
using std::stack;
using std::min;
using std::max;
/*Solution I using stack 
class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3) return 0;
        stack<int> s;
        int sum = 0;
        s.push(0);
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                int low = s.top();
                s.pop();
                while (!s.empty()) {
                    int high = s.top();
                    sum += (i - high - 1) * (min(A[high], A[i]) - A[low]);
                    if(A[high] > A[i]) break;
                    s.pop();
                    low = high;                    
                }
            }
            s.push(i);
        }
        return sum;
    }
};
*/
/* minor changes Solution I' 
class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3) return 0;
        stack<int> s;
        int sum = 0;
        s.push(0);
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                int low = s.top();
                s.pop();
                while (!s.empty() && A[s.top()] <= A[i]) {
                    sum += (i - s.top() - 1) * (A[s.top()] - A[low]);
                    low = s.top();   
                    s.pop();
                }
                if (!s.empty()) sum += (i - s.top() - 1) * (A[i] - A[low]);
            }
            s.push(i);
        }
        return sum;
    }
};
*/
/* Solution II Two pointers */
class Solution {
public:
    int trap(int A[], int n) {
        if (n < 3) return 0;
        int sum = 0;
        vector<int> left(n, 0), right(n, 0);
        for (int i = n - 2; i >= 1; i--) {
            right[i] = max(right[i + 1], A[i + 1]);
        }
        for (int i = 1; i <= n - 2; i++) {
            left[i] = max(left[i - 1], A[i - 1]);
            int water = min(left[i], right[i]);
            if (water > A[i]) sum += water - A[i];
        }
        return sum;
    }
};
int main() {
}
