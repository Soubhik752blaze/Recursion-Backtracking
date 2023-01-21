// Question :- Check if the given string is a palindrome
#include <bits/stdc++.h>
using namespace std;

bool checkpalindrome(int l, int r, char arr[])
{
    if (l >= r)
        return true;
    if (arr[l] != arr[r])
        return false;
    checkpalindrome(l + 1, r - 1, arr);
}
int main()
{
    int N;
    cout << "Enter Value of N :- ";
    cin >> N;
    if (N <= 1)
    {
        cout << "palindrome";
        return 0;
    }
    char arr[N];
    cout << "Enter Values of array ---> ";
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = checkpalindrome(0, N - 1, arr);
    ans ? cout << "A palindrome" : cout << "Not a palindrom"; 

    return 0;
}

// TC -> O(N/2)
// SC -> O(1)
