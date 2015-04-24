#include <vector>
using std::vector;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (m != 9 || n != 9) return false;
        for (int i = 0; i < 9; i++) {
            vector<bool> test(9, false);
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int num = c - '1';
                    //if (num > 8 || num < 0) return false;
                    if (test[num]) return false;
                    else test[num] = true;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> test(9, false);
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c != '.') {
                    int num = c - '1';
                    //if (num > 8 || num < 0) return false;
                    if (test[num]) return false;
                    else test[num] = true;
                }
            }
        }
        for (int i = 0; i < 9; i = i + 3) 
            for (int j = 0; j < 9; j = j + 3) {
                vector<bool> test(9, false);
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        char c = board[i + x][j + y];
                        if (c != '.') {
                            int num = c - '1';
                            //if (num > 8 || num < 0) return false;
                            if (test[num]) return false;
                            else test[num] = true;
                        }
                    }
                }
            }
        return true;    
    }
};
int main() {
}
