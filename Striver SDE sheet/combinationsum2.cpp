/* Question :- Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x.
The same repeated number cant be chosen from arr[] multiple number of times. Also the combinations must be sorted.*/

#include <bits/stdc++.h>
using namespace std;

void combsum(int ind, int n, int arr[], vector<int> &res, vector<vector<int>> &ans, int target)
{

    //base case
    // if at any point of time, we found a suitable combination, we store it and stop the recursive chain
    if (target == 0)
    {
        ans.push_back(res);
        return;
    }

    // for every element i, see whether the prev element is same as this element or not, if yes we dont choose it
    // we also keep a check for arr[i] > target, if its fulfilled we dont go forward and break the loop
    // this is because the array is sorted and if already arr[i] > target, there is no point moving more right
    // if the prev element is not same as current element, then we move to include this in our result and move forward
    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;

        res.push_back(arr[i]);
        combsum(i + 1, n, arr, res, ans, target - arr[i]);
        //back-track
        res.pop_back();
    }
}
int main()
{
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    int n = 7;
    vector<int> res;
    vector<vector<int>> ans;
    int target = 8;

    sort(arr, arr + n);
    cout << "Such combinations are:-" << endl;
    combsum(0, n, arr, res, ans, target);
    for (auto it : ans)
    {
        for (auto x : it)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// Code by Blaze
//  TC O(2^n * k) and SC - changes according to ans. in general O(k * x)