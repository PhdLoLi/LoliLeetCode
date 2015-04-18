#include <iostream>
#include <vector>
using std::vector;
/* Solution I
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> sol;
        vector<bool> test(S.size(), false);
        ret.push_back(sol);
        subsets(ret, sol, S, test, 0);
        return ret;
    }
    void subsets(vector<vector<int> > &ret, vector<int> &sol, vector<int> &S, vector<bool> &test, int start) {
        for (int i = start; i < S.size(); i++) {
            if (i > 0 && S[i] == S[i - 1] && (test[i - 1] == false)) {
                
            }
            else {
                sol.push_back(S[i]);
                test[i] = true;
                ret.push_back(sol);
                subsets(ret, sol, S, test, i + 1);
                sol.pop_back();
                test[i] = false;
            }
        }
    }
};
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> sol;
        ret.push_back(sol);
        subsets(ret, sol, S, 0);
        return ret;
    }
    void subsets(vector<vector<int> > &ret, vector<int> &sol, vector<int> &S, int start) {
        for (int i = start; i < S.size(); i++) {
            if (i > start && S[i] == S[i - 1]) continue;
            else {
                sol.push_back(S[i]);
                ret.push_back(sol);
                subsets(ret, sol, S, i + 1);
                sol.pop_back();
            }
        }
    }
};
int main() {
  Solution so;

}
