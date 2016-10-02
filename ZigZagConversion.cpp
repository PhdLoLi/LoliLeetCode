#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.empty()) return s;
        vector<string> res(numRows);
        int i = 0;
        do {
            for (int j = 0; j < numRows && i < s.size(); j++, i++) {
                res[j].push_back(s[i]);
            }
            for (int j = numRows - 2; j > 0 && i < s.size(); j--, i++) {
                res[j].push_back(s[i]);    
            }
        } while (i < s.size());
        string ss;
        for (int j = 0; j < numRows; j++) ss.append(res[j]);
//        cout << ss << endl;
        return ss;
    }
};
int main() {
  Solution so;
  string s = "PAYPALISHIRING";
  int numRows = 3;
  so.convert(s, numRows);
}
