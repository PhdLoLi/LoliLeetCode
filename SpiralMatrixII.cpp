#include <vector>
using std::vector;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        int start = 0, end = n - 1, num = 1;
        while (start < end) {
            for (int i = start; i < end; i++)
                res[start][i] = num++;
            for (int i = start; i < end; i++)
                res[i][end] = num++;
            for (int i = end; i > start; i--) 
                res[end][i] = num++;
            for (int i = end; i > start; i--) 
                res[i][start] = num++;
            start ++;
            end --;
        }
        if (start == end)
            res[start][end] = num;
        return res;
    }
};
int main () {
}
