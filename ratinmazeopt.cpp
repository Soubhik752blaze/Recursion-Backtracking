#include <bits/stdc++.h>
using namespace std;

class solution {
  void solve(int i, int j, vector < vector < int >> & maze, int n, vector < string > & ans, string res,
  vector < vector < int >> & vis, int di[], int dj[]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(res);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && maze[nexti][nextj] == 1) {
        vis[i][j] = 1;
        solve(nexti, nextj, maze, n, ans, res + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> &maze, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      int di[] = { +1, 0, 0,-1};
      int dj[] = { 0, -1, 1, 0};
      if (maze[0][0] == 1) solve(0, 0, maze, n, ans, "", vis, di, dj);
      return ans;
    }
};

int main() {
  int n = 4;

 vector < vector < int >> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
   
  solution obj;
  vector < string > result = obj.findPath(maze, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}

 /*Code by Blaze
     Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
     Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).*/