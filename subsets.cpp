#include <iostream>
#include <vector>
using std::vector;
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
int main() {
  Solution so;

}
