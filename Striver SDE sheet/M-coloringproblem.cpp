/*Question :- Given an undirected graph and an integer M.
The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color.
Here coloring of a graph means the assignment of colors to all vertices.
Print 1 if it is possible to colour vertices and 0 otherwise. */
// C++ program for solution of M
// Coloring problem using backtracking

#include <bits/stdc++.h>
using namespace std;
#define V 4

//function to check if a vertex v can be colored with color "c"
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if ( v!= i && graph[v][i] && c == color[i])
            return false;

    return true;
}

bool solve(bool graph[V][V], int m, int color[], int v)
{

    // base case: If all vertices are assigned a color then return true
    if (v == V)
        return true;

    /* Consider this vertex v and try different colors */
    for (int c = 1; c <= m; c++)
    {
        // if the vertex v can be colored with color "col"
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (solve(graph, m, color, v + 1))
                return true;
            // back-track
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[V][V], int m)
{

    int color[V] = {0};
    return solve(graph, m, color, 0);
}

int main()
{
    //adjacency matrix used
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    int m = 3;

    cout << "Possibility of coloring the graph with at most m colors ? Ans :- " << (graphColoring(graph, m) ? "Yes" : "No" );
    return 0;
}

// TC is almost O(N^m)
// SC is O(N) for color array + O(N) ASS
