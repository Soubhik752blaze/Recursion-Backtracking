/*Question:- Consider a rat placed at (0, 0) in a square matrix of order N * N.
It has to reach the destination at (N – 1, N – 1).
Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right).
Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

Note: In a path, no cell can be visited more than one time.

Print the answer in lexicographical(sorted) order*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
  void solve(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string res,
             vector<vector<int>> &vis, int di[], int dj[])
  {
    if (i == n - 1 && j == n - 1)
    {
      ans.push_back(res);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && maze[nexti][nextj] == 1)
      {
        vis[i][j] = 1;
        solve(nexti, nextj, maze, n, ans, res + dir[ind], vis, di, dj);
        vis[i][j] = 0;
      }
    }
  }

public:
  vector<string> findPath(vector<vector<int>> &maze, int n)
  {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    if (maze[0][0] == 1)
      solve(0, 0, maze, n, ans, "", vis, di, dj);
    return ans;
  }
};

int main()
{
  int n = 4;

  vector<vector<int>> maze = {{1, 0, 0, 0},
                              {1, 1, 0, 1},
                              {1, 1, 0, 0},
                              {0, 1, 1, 1}};

  solution obj;
  vector<string> result = obj.findPath(maze, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++)
      cout << result[i] << " ";
  cout << endl;

  return 0;
}

/*
 Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
 Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).*/