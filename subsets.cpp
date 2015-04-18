#include <iostream>
#include <vector>
using std::vector;
/*Solution I Mine 
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        ret.push_back(vector<int>());
        for (int i = 0; i < S.size(); i++) {
            int len = ret.size();
            for (int j = 0; j < len; j++) {
                vector<int> tmp = ret[j];
                tmp.push_back(S[i]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
*/
/* Solution II backtracking */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> sol;
        ret.push_back(sol);
        subsets(ret, sol, S, 0);
        return ret;
    }
    void subsets(vector<vector<int> > &ret, vector<int> &sol, vector<int> &S, int start) {
        for (int i = start; i < S.size(); i++) {
            sol.push_back(S[i]);
            ret.push_back(sol);
            subsets(ret, sol, S, i + 1);
            sol.pop_back();
        }    
    }
};
/* Solution III bit manipulation
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        unsigned long long num = pow(2, S.size());
        //ret.push_back(vector<int>());
        for (unsigned long long i = 0; i < num; i++)
            bitmap(ret, S, i);   
        return ret;
    }
    void bitmap(vector<vector<int> > &ret, vector<int> &S, int i) {
        vector<int> sol;
        int digit = 0;
        while (i != 0) {
            if (i & 0x01 == 1)
                sol.push_back(S[digit]);
            i >>= 1;
            digit++;
        }
        ret.push_back(sol);
    }
};
*/
int main() {
  Solution so;

}
