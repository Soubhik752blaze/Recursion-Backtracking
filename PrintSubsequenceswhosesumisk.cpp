// Question :- Print all subsequences of a string whose sum is equal to K

#include <bits/stdc++.h>
using namespace std;
int k;
void printit(vector<int> &res)
{
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    return;
}
void printsubsequence(int ind, int n, int arr[], vector<int> &res, int sum, int k)
{
    if (ind == n)
    {
        if (sum == k)
            printit(res);
        return;
    }

    // take or pick the element to be in your subsequence
    res.push_back(arr[ind]);
    sum += arr[ind];
    printsubsequence(ind + 1, n, arr, res, sum, k);
    res.pop_back();
    sum -= arr[ind];

    // Donot take or pick the element to be in your subsequence
    printsubsequence(ind + 1, n, arr, res, sum, k);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    vector<int> res;
    int target = 5;
    cout << "The list of such subsequences are :- " << endl;
    printsubsequence(0, n, arr, res, 0, target);
    return 0;
}

// Code by Blaze
//TC -> O(2^n)
//SC -> O(N) as ASS
