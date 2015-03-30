#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using std::string;
using std::vector;
/* V0 My version
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string>({""});
        vector<string> allsol;
        string sol = "";
        tryParenthesis(allsol, sol, n);
        return allsol;
    }
    void tryParenthesis(vector<string> &allsol, string &sol, int n) {
        if (sol.size() == n * 2) {
            string res(sol);
            allsol.push_back(sol);
            return;
        }
        for (int j = 0; j < 2; j++) {
            if (j == 0) sol.push_back('(');
            else sol.push_back(')');
            if (validPos(sol, n)) {
                tryParenthesis(allsol, sol, n);
                sol.pop_back();
            } else sol.pop_back();
        }       
    }
    bool validPos(string &sol, int n) {
        int countL = 0, countR = 0;
        for (int i = 0; i < sol.size(); i++) {
            if (sol[i] == '(')
            {
              countL++;
            } else countR++;
              if (countL > n || countL < countR)
                return false;
        }
        return true;
    }
};
*/

/*Add lenL lenR to record the length of ( & ), it's more easy*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allsol;
        string sol;
        tryParenthesis(0, 0, allsol, sol, n);
        return allsol;
    }
    void tryParenthesis(int lenL, int lenR, vector<string> &allsol, string &sol, int n) {
        if (lenL == n && lenR == n) {
            allsol.push_back(sol);
            return;
        }
        if (lenL < n) {
            sol.push_back('(');
            tryParenthesis(lenL + 1, lenR, allsol, sol, n);
            sol.pop_back();
        }
        if (lenR < lenL) {
            sol.push_back(')');
            tryParenthesis(lenL, lenR + 1, allsol, sol, n);
            sol.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {
  Solution so;
  int n = 2;
  if (argc > 1)
    n = atoi(argv[1]);
  std::cout << "n " << n <<std::endl;
  vector<string> v =  so.generateParenthesis(n);  
  std::cout << "size " << v.size() << std::endl;
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << std::endl;
}
