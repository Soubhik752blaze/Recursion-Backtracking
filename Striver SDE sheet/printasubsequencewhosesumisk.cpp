// Question :- Print any 1 subsequences of an array whose sum is equal to K
#include <bits/stdc++.h>
using namespace std;
int k;

bool printsubsequence(int ind, int n, int arr[], vector<int> &res, int sum, int k)
{
    if (ind == n)
    {
        if (sum == k)
        {
            // condition satisfied
            for (auto it : res)
                cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        return false;
    }

    // take or pick the element to be in your subsequence
    res.push_back(arr[ind]);
    sum += arr[ind];
    if (printsubsequence(ind + 1, n, arr, res, sum, k))
        return true;
    //backtrack
    res.pop_back();
    sum -= arr[ind];

    // Donot take or pick the element to be in your subsequence
    if (printsubsequence(ind + 1, n, arr, res, sum, k))
        return true;

    return false;
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;
    vector<int> res;
    int target = 5;
    printsubsequence(0, n, arr, res, 0, target) ? cout << "True" : cout << "False";
    return 0;
}

// Code by Blaze
//TC -> O(2^n)
//SC -> O(N) as ASS
