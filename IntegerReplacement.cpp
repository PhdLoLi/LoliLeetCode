#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int integerReplacement(int n) {
  long long t = n;int cnt = 0;
    while (t > 1) {
      ++cnt;
        if (t & 1) {
            if ((t & 2) && (t != 3)) ++t;
            else --t;
        } else {
            t >>= 1;
        }
    }
    return cnt;
}
class NumArray {
public: 
    vector<vector<int>> res; 
//    vector<vector<bool>> mark;
    NumArray(vector<int> &nums) {
        int n = nums.size();
        res.resize(n, vector<int> (n, 0));
//        mark.resize(nums.size(), vector<bool> (nums.size(), false));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += nums[j];
                res[i][j] = sum;
            }
        }
    }

    int sumRange(int i, int j) {
       return res[i][j]; 
    }
};
int main() {
}
