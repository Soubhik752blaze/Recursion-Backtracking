// Print all permutations of a string/array - Approach 2

#include <bits/stdc++.h>
using namespace std;

void printpermutations(int index, vector<int> &arr, vector<vector<int>> &ans)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
    }

    // take or pick the element to be in your subsequence
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        printpermutations(index + 1, arr, ans);
        swap(arr[index], arr[i]);
    }

    // Donot take or pick the element call is not present since every element has to be present in your permutation
}
int main()
{
    int n = 3;
    vector<int> arr = {1,2,3};
    cout << "The permutations possible are:- " << endl;
    vector<vector<int>> ans;
    printpermutations(0, arr, ans);
    for (auto it : ans)
    {
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

// Code by Blaze     TC(n)= n!*n  SC(n)= o(n)
