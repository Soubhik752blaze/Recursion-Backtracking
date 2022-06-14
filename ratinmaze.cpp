/*Rat in a maze problem. with directions to move as Down Up Right and Left.
print all possible routes in lexological order*/

#include<bits/stdc++.h>
using namespace std;

class solution
{   
    void checkandprintpath(int i,int j,vector<vector<int>> &maze,vector<string> &ans, int n, string res, vector<vector<int>> &vis)
    {
        if(i == n-1 && j == n-1 )
        {
            ans.push_back(res);
            return;
        }

        //Downward Movement
        if(i+1<n && vis[i+1][j]==0 && maze[i+1][j]==1)
        {
            vis[i][j]=1;
            checkandprintpath(i+1,j,maze,ans,n,res+'D',vis);
            vis[i][j]=0;
        }

        //Leftward Movement
         if(j-1>=0 && vis[i][j-1]==0 && maze[i][j-1]==1)
        {
            vis[i][j]=1;
            checkandprintpath(i,j-1,maze,ans,n,res + 'L',vis);
            vis[i][j]=0;
        }

        //Rightward movement
        if(j+1<n && vis[i][j+1]==0 && maze[i][j+1]==1)
        {
            vis[i][j]=1;
            checkandprintpath(i,j+1,maze,ans,n,res + 'R',vis);
            vis[i][j]=0;
        }

        //Upward movement
        if(i-1>=0 && vis[i-1][j]==0 && maze[i-1][j]==1)
        {
            vis[i][j]=1;
            checkandprintpath(i-1,j,maze,ans,n,res + 'U',vis);
            vis[i][j]=0;
        }
    }

public:
    vector<string> findpath(vector<vector<int>> &maze, int n )
    {
        vector<string> ans;
        vector<vector<int>> vis;
        for(int i=0;i<n;i++)
            vis.push_back(vector<int> (n,0));
        if(maze[0][0]==1)
            checkandprintpath(0,0,maze,ans,n,"",vis);
        return ans;
    }    
};

int main()
{
    vector < vector < int >> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int n = 4;
    solution obj;
    vector < string > result = obj.findpath(maze, n);
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++) 
            cout << result[i] << " ";
    cout << endl; 
    return 0;
    
}

    /*Code by Blaze
     Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
        Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).*/