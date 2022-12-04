/*Question :- Rat in a maze problem, Go from (0,0) to (n-1,n-1) with directions to move given as -> Down, Up, Right and Left.
Print all possible routes in lexological order*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
    void checkandprintpath(int i, int j, vector<vector<int>> &maze, vector<string> &ans, int n, string res, vector<vector<int>> &vis)
    {
        // base-case
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(res);
            return;
        }

        // general scenario
        //  Downward Movement
        if (i + 1 < n && vis[i + 1][j] == 0 && maze[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            checkandprintpath(i + 1, j, maze, ans, n, res + 'D', vis);
            // back-track
            vis[i][j] = 0;
        }

        // Leftward Movement
        if (j - 1 >= 0 && vis[i][j - 1] == 0 && maze[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            checkandprintpath(i, j - 1, maze, ans, n, res + 'L', vis);
            // back-track
            vis[i][j] = 0;
        }

        // Rightward movement
        if (j + 1 < n && vis[i][j + 1] == 0 && maze[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            checkandprintpath(i, j + 1, maze, ans, n, res + 'R', vis);
            // back-track
            vis[i][j] = 0;
        }

        // Upward movement
        if (i - 1 >= 0 && vis[i - 1][j] == 0 && maze[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            checkandprintpath(i - 1, j, maze, ans, n, res + 'U', vis);
            // back-track
            vis[i][j] = 0;
        }
    }

public:
    vector<string> findpath(vector<vector<int>> &maze, int n)
    {
        vector<string> ans;
        // initialising visited vector to check which cells are visited
        vector<vector<int>> vis(n, vector<int>(n, 0));
        // just a check if starting position is unblocked
        if (maze[0][0] == 1)
            checkandprintpath(0, 0, maze, ans, n, "", vis);
        return ans;
    }
};

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    int n = 4;
    solution obj;
    vector<string> result = obj.findpath(maze, n);
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;
    return 0;
}

/*Code by Blaze
 Time Complexity: O(4^(n*n)), because on every cell we need to try 4 different directions.
 Space Complexity:  O(n*n) ,Maximum Depth of the recursion tree(auxiliary space).*/