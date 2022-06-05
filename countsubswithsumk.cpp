// Count all subsequences of a string whose sum is equal to K


#include<bits/stdc++.h>
using namespace std;
int k;

int countsubsequence(int ind,int n, int arr[],int sum)
{
    if (ind==n)
        { 
            if(sum==k)
                return 1;
            else 
                return 0;
        }
    
    //take or pick the element to be in your subsequence
    sum+=arr[ind];
    int l = countsubsequence(ind+1,n,arr,sum);
    sum-=arr[ind];

    //Donot take or pick the element to be in your subsequence
    int r = countsubsequence(ind+1,n,arr,sum);

    return l+r;                 /*starting from end cases, start adding up counts for both taken and non taken cases
                                    and start cumulating with the help of recursion*/
    
}
int main()
{
    int n;
    cout<<"Enter value of n :-";
    cin>>n;
    if(n<=0)
       {
            cout<<"wrong Input";
            return 0;
       }
    cout<<"Enter the values :- ";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter value of k :- ";
    cin>>k;
    if(k==0)
        {
            cout<<"{}";
            return 0;
        }
    cout<<"The count of such subsequences are :- "<<countsubsequence(0,n,arr,0);
    return 0;
    
}

    //Code by Blaze
