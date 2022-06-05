/* Given NxN chessboard, Place N queens in it such that 
    1. Every row has a queen.
    2. Every Column has a queen.
    3. None of the queens attack each other. */

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool issafe( int row, int col, vector < string > &board, int n){
        int duprow = row;
        int dupcol = col;

        //check for upper diagonal
        while(row>=0 && col>=0)
        {   
            
            if(board[row][col]=='Q')
                return false;

            row--;
            col--;    
        }

        col = dupcol;
        row = duprow;
        

        //check for left row
        while(col>=0)
        {   
            
            if(board[row][col]=='Q')
                return false;
            col--;

        }

        row = duprow;
        col = dupcol;
        //check for lower diagonal
        while(row<n && col>=0)
        {   
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;

    }
public:
    void solve(int col, vector < string > &board, vector < vector < string >> &ans,int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(issafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    
    }

public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans,n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j]<< " ";
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}


    //Code by Blaze   TC--O(N!) , SC-- O(N*N) -> NxN chessboard.



