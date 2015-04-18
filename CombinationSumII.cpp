#include <iostream>
#include <vector>
using std::vector;
/* Solution I 
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        vector<int> sol;
        combinationSum(num, target, 0, sol, ret);
        return ret;
    }
    void combinationSum(vector<int> &num, int target, int start, vector<int> &sol, vector<vector<int> > &ret) {
        for (int i = start; i < num.size(); i++) {
            if (i > start && num[i] == num[i - 1]) continue;
            if (target == num[i]) {
                sol.push_back(num[i]);
                ret.push_back(sol);
                sol.pop_back();
                return;
            }
            if (target > num[i]) {
                sol.push_back(num[i]);
                target -= num[i];
                combinationSum(num, target, i + 1, sol, ret);
                sol.pop_back();
                target += num[i];
            } else break;
        }    
    }
};
*/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > ret;
        vector<int> sol;
        combinationSum(num, target, 0, sol, ret);
        return ret;
    }
    void combinationSum(vector<int> &num, int target, int start, vector<int> &sol, vector<vector<int> > &ret) {
        if (target == 0) {
            ret.push_back(sol);
            return;
        }
        for (int i = start; i < num.size(); i++) {
            if (i > start && num[i] == num[i - 1]) continue;
            if (target >= num[i]) {
                sol.push_back(num[i]);
                combinationSum(num, target - num[i], i + 1, sol, ret);
                sol.pop_back();
            } else break;
        }    
    }
};
int main() {
  Solution so;

}
