#include <vector>
using std::vector;
/*
class Solution {
public:
    int findMin(vector<int> &num) {
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i + 1] < num[i])
                return num[i + 1];
        }
        return num[0];
    }
};
*/
/*iterative */
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, h = num.size() - 1;
        if (num[l] < num[h]) return num[l];
        while (l < h) {
            int m = (l + h) / 2;
            if (num[m] < num[h])
                h = m;
            else
                l = m + 1;
        }
        return num[l];
    }
};
/* recursive version
class Solution {
public:
    int findMin(vector<int> &num) {
        return bsMin(num, 0 , num.size() - 1);
    }
    int bsMin(vector<int> &num, int low, int high) {
        if(num[low] <= num[high]) return num[low];
        int mid = (low + high) / 2;
        if (num[mid] < num[high])
            return bsMin(num, low, mid);
        else 
            return bsMin(num, mid + 1, high);
    }
};
*/
int main() {}
