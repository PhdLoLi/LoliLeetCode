#include <iostream>
#include <vector>
using std::vector;
/* Solution I
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> sol;
        combinationSum(candidates, target, 0, sol, ret);
        return ret;
    }
    void combinationSum(vector<int> &candidates, int target, int start, vector<int> &sol, vector<vector<int> > &ret) {
        for (int i = start; i < candidates.size(); i++) {
            if (target == candidates[i]) {
                sol.push_back(candidates[i]);
                ret.push_back(sol);
                sol.pop_back();
                return;
            }
            if (target > candidates[i]) {
                sol.push_back(candidates[i]);
                target -= candidates[i];
                combinationSum(candidates, target, i, sol, ret);
                sol.pop_back();
                target += candidates[i];
            } else break;
        }    
    }
};
*/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> sol;
        combinationSum(candidates, target, 0, sol, ret);
        return ret;
    }
    void combinationSum(vector<int> &candidates, int target, int start, vector<int> &sol, vector<vector<int> > &ret) {
        if (target == 0) {
            ret.push_back(sol);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                sol.push_back(candidates[i]);
                combinationSum(candidates, target - candidates[i], i, sol, ret);
                sol.pop_back();
            } else break;
        }    
    }
};
int main() {
  Solution so;

}
