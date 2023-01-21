/*Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x.
The same repeated number may be chosen from arr[] unlimited number of times.*/

#include <bits/stdc++.h>
using namespace std;
int k;

void combsum(int ind, int n, int target, int arr[], vector<int> &res, vector<vector<int>> &ans)
{

    if (ind == n)
    {
        if (target == 0)
        {
            ans.push_back(res);
        }
        return;
    }
    // picks the element and hence target reduced and also since chance of picking it up again so index not increased
    if (arr[ind] <= target)
    {
        res.push_back(arr[ind]);
        combsum(ind, n, target - arr[ind], arr, res, ans);
        res.pop_back();
    }

    // Doesnot pick the element and hence target not reduced and also index + 1
    combsum(ind + 1, n, target, arr, res, ans);
}
int main()
{
    int arr[] = {2,3,4,5};
    int n = 4;
    vector<int> res;
    vector<vector<int>> ans;
    int k = 8;
    cout << "Such combinations :-" << endl;
    combsum(0, n, k, arr, res, ans);
    for (auto it : ans)
    {
        for (auto x : it)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// Code by Blaze
//  TC O(2^t * k), where t is target and k is avg length of fit subsequence
// and SC - changes according to ans. in general O(k * x)