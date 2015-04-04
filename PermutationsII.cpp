#include <vector>
using std::vector;
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() == 0) return res;
        vector<int> sol;
        vector<int> test(num.size(), 0);
        vector<int> dup(num.size(), -1);
        for (int i = 0; i < dup.size(); i++) {
            if (dup[i] > -1) continue;
            int k = i;
            for (int j = i + 1; j < dup.size(); j++) {
                if (num[j] == num[i]) {
                    dup[j] = k;
                    k = j;
                }
            }
        }
        permuteBT(num, res, sol, test, dup);
        return res;
    }
    void permuteBT(vector<int> &num, vector<vector<int> > &res, vector<int> &sol, vector<int> &test, vector<int> &dup) {
        if (sol.size() == num.size()) {
            res.push_back(sol);
            return;    
        }
        for (int j = 0; j < num.size(); j++) {
            if (test[j] == 0 && (dup[j] == -1 || (dup[j] > -1 && test[dup[j]] == 1))) {
                sol.push_back(num[j]);
                test[j] = 1;
                permuteBT(num, res, sol, test, dup);
                sol.pop_back();
                test[j] = 0;
            }
        }
    }
};
int main() {
}
