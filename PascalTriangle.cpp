#include <vector>
using std::vector;
/* Solution I
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if (numRows == 0) return ret;
        ret.push_back(vector<int> (1,1));
        for (int i = 1; i < numRows; i++) {
            vector<int> line;
            line.push_back(1);
            for (int j = 1; j < i; j++) {
                line.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            }
            line.push_back(1);
            ret.push_back(line);
        }
        return ret;
    }
};
*/
/* Solution II */
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if (numRows == 0) return ret;
        ret.push_back(vector<int> (1,1));
        for (int i = 1; i < numRows; i++) {
            vector<int> line;
            line.push_back(1);
            for (int j = 1; j <= i / 2; j++) 
                line.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            for (int j = (i - 1) / 2; j >= 0; j--)
                line.push_back(line[j]);
            ret.push_back(line);
        }
        return ret;
    }
};
int main() {
}
