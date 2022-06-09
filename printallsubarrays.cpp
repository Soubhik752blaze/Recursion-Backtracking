// Print all subarrays of a string

 
#include <bits/stdc++.h>
using namespace std;
 
// Recursive function to print all possible subarrays for
// given array
void printSubArrays(vector<int> arr, int start, int end)
{
    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;
    // Increment the end point and start from 0
    else if (start > end)
        printSubArrays(arr, 0, end + 1);
    // Print the subarray and increment the starting point
    else {
        cout << "[";
        for (int i = start; i < end; i++)
            cout << arr[i] << ", ";
        cout << arr[end] << "]" << endl;
        printSubArrays(arr, start + 1, end);
    }
    return;
}
 
int main()
{
    int n,k;
    cout<<"Enter value of n :-";
    vector<int> arr;
    cin>>n;
    if(n<1)
    {
        cout<<"No subarray present";
        return 0;
    }
    cout<<"Enter the values :- ";
    for(int i=0;i<n;i++)
    {
        cin>>k;
        arr.push_back(k);

    }
    cout<<"The sub arrays are :-"<<endl;  
    printSubArrays(arr, 0, 0);
    return 0;
}
 
//Code by Blaze   ------ TC O(n^2)

