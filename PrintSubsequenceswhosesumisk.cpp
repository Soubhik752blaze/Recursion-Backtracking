// Print all subsequences of a string whose sum is equal to K


#include<bits/stdc++.h>
using namespace std;
int k;
void printit(vector<int> &res)
{
    for (auto it: res)
        cout<<it<<" ";
    cout<<endl;    
    return; 
}
void printsubsequence(int ind,int n, int arr[], vector<int> &res,int sum)
{
    if (ind==n)
        {
            if(sum==k)
                printit(res);
            return;
        }
    
    //take or pick the element to be in your subsequence
    res.push_back(arr[ind]);
    sum+=arr[ind];
    printsubsequence(ind+1,n,arr,res,sum);
    res.pop_back();
    sum-=arr[ind];

    //Donot take or pick the element to be in your subsequence
    printsubsequence(ind+1,n,arr,res,sum);
    
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
    vector<int> res;
    cout<<"The list of such subsequences are :- "<<endl;
    printsubsequence(0,n,arr,res,0);
    return 0;
    
}

    //Code by Blaze

