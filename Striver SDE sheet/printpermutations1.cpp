// Print all permutations of a string/array - Approach 1

#include <bits/stdc++.h>
using namespace std;

void printpermutations(int n, int arr[], vector<int> &res, int hash[])
{
    if (res.size() == n)
    {
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        return;
    }

    // take or pick the element to be in your subsequence
    for (int i = 0; i < n; i++)
        if (!hash[i])
        {
            res.push_back(arr[i]);
            hash[i] = 1;
            printpermutations(n, arr, res, hash);
            res.pop_back();
            hash[i] = 0;
        }

    // Donot take or pick the element call is not present since every element has to be present in your permutation
}
int main()
{
    int n;
    cout << "Enter value of n :-";
    cin >> n;
    if (n <= 0)
    {
        cout << "wrong Input";
        return 0;
    }
    cout << "Enter the values :- ";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "The permutations possible are:- " << endl;
    vector<int> res;
    int hash[n] = {0};
    printpermutations(n, arr, res, hash);
}

// Code by Blaze
// TC(n)= n! if no storage need(only print) and n!*n if storage is needed...... SC(n)= o(n)
