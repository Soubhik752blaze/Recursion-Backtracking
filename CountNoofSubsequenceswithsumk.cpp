// Question :- Count all subsequences of a string whose sum is equal to K

#include <bits/stdc++.h>
using namespace std;

int countsubsequence(int ind, int n, int arr[], int sum, int target)
{
    if (ind == n)
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }

    // take or pick the element to be in your subsequence
    sum += arr[ind];
    int l = countsubsequence(ind + 1, n, arr, sum, target);
    sum -= arr[ind];

    // Donot take or pick the element to be in your subsequence
    int r = countsubsequence(ind + 1, n, arr, sum, target);

    return l + r; /*starting from end cases, start adding up counts for both taken and non taken cases
                      and start cumulating with the help of recursion*/
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int target = 5;
    cout << "The count of such subsequences are :- " << countsubsequence(0, n, arr, 0, target);
    return 0;
}

// Code by Blaze
