#include <vector>
#include <string>
#include <iostream>

using std::vector;
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > row(9, vector<bool>(9, false));
        vector<vector<bool> > col(9, vector<bool>(9, false));
        vector<vector<bool> > squ(9, vector<bool>(9, false));
        //row init
        for (int i = 0; i < 9; i++) 
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int num = c - '1';
                    if (row[i][num]) return;
                    row[i][num] = true;
                }
            }
        //column init
        for (int i = 0; i < 9; i++) 
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c != '.') {
                    int num = c - '1';
                    if (col[i][num]) return;
                    col[i][num] = true;
                }
            }
        //square init
        for (int i = 0; i < 9; i = i + 3) 
            for (int j = 0; j < 9; j = j + 3) 
                for (int x = 0; x < 3; x++) 
                    for (int y = 0; y < 3; y ++) {
                        char c = board[i + x][j + y];
                        if (c != '.') {
                            int num = c - '1';
                            if (squ[i + j / 3][num]) return;
                            squ[i + j / 3][num] = true;
                        }
                    }
    //    std::cout << "HERE" << std::endl;
        solveSudoku(row, col, squ, board, 0, 0);
    }
    bool solveSudoku(vector<vector<bool> > &row, vector<vector<bool> > &col, vector<vector<bool> > &squ, vector<vector<char> > &board, int i, int j) {
        if (i == 9) return true;
        char c = board[i][j];
        int ii, jj;
        if (j == 8) {
          ii = i + 1;
          jj = 0;
        } else {
          ii = i;
          jj = j + 1;
        }
        if (c != '.')  return solveSudoku(row, col, squ, board, ii, jj);
         // std::cout << "(" << i << "," << j << ")  ";
        for (int k = 0; k < 9; k++)
            if (!row[i][k] && !col[j][k] && !squ[i / 3 * 3 + j / 3][k]) {
                row[i][k] = true;
                col[j][k] = true;
                squ[i / 3 * 3 + j / 3][k] = true;
                board[i][j] = '1' + k;
                if (solveSudoku(row, col, squ, board, ii, jj)) return true;
                row[i][k] = false;
                col[j][k] = false;
                squ[i / 3 * 3 + j / 3][k] = false;
            }
        board[i][j] = '.';
        return false;     
    }
};

void printVV(vector<vector<char> > &board) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          std::cout << board[i][j] << " ";
        }
      std::cout << " " << std::endl;
    }
}
/* Others Good
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        if(board.size()<9 || board[0].size()<9) return;
        bool findSol = solSudoku(board, 0, 0);
    }
    
    bool solSudoku(vector<vector<char>> &board, int irow, int icol) {
        if(irow==9) return true;
        
        int irow2, icol2;
        if(icol==8) {
            irow2 = irow+1;
            icol2 = 0;
        }
        else {
            irow2 = irow;
            icol2 = icol+1;
        }
        
        if(board[irow][icol]!='.') {
            if(!isValid(board, irow, icol)) return false;
            return solSudoku(board, irow2, icol2);
        }
        
        for(int i=1; i<=9; i++) {
            board[irow][icol] = '0'+i;
            if(isValid(board, irow, icol) && solSudoku(board, irow2, icol2)) return true;
        }
        
        // reset grid 
        board[irow][icol] = '.';
        return false;
    }
    
    bool isValid(vector<vector<char>> &board, int irow, int icol) {
        char val = board[irow][icol];
        if(val-'0'<1 || val-'0'>9) return false;
        
        // check row & col
        for(int i=0; i<9; i++) {
            if(board[irow][i]==val && i!=icol) return false;
            if(board[i][icol]==val && i!=irow) return false;
        }
        
        //check 3x3 box
        int irow0 = irow/3*3;
        int icol0 = icol/3*3;
        for(int i=irow0; i<irow0+3; i++) {
            for(int j=icol0; j<icol0+3; j++) {
                if(board[i][j]==val && (i!=irow || j!=icol)) return false;
            }
        }
        
        return true;
    }
};
*/
int main() {
  Solution so;
  vector<vector<char> > board = {
    {'.', '.', '9', '7', '4', '8', '.', '.', '.'},
    {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
    {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
    {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
    {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
    {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
    {'.', '.', '.', '2', '7', '5', '9', '.', '.'}
  }; 
  so.solveSudoku(board);
  printVV(board);

//  std::string s = "..9748...";
//  board.push_back(std::vector<char>(s.begin(), s.end()));

//  board.push_back("7........");
//  board.push_back(".2.1.9...");
//  board.push_back("..7...24.");
//  board.push_back(".64.1.59.");
//  board.push_back(".98...3..");
//  board.push_back("...8.3.2.");
//  board.push_back("........6");
//  board.push_back("...2759..");
}
