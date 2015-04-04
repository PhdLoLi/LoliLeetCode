#include <vector>
using std::vector;
/* backtracking way */
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() == 0) return res;
        vector<int> sol;
        vector<int> test(num.size(), 0);
        permuteBT(num, res, sol, test);
        return res;
    }
    void permuteBT(vector<int> &num, vector<vector<int> > &res, vector<int> &sol, vector<int> &test) {
        if (sol.size() == num.size()) {
            res.push_back(sol);
            return;    
        }
        for (int j = 0; j < num.size(); j++) {
            if (test[j] == 0) {
                sol.push_back(num[j]);
                test[j] = 1;
                permuteBT(num, res, sol, test);
                sol.pop_back();
                test[j] = 0;
            }
        }
    }
};
/*DP or Insertion Way But different order*/
int main() {

}
