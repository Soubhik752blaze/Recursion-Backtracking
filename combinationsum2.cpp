/*Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. 
The same repeated number cant be chosen from arr[] multiple number of times. Also the combinations must be sorted.*/

#include<bits/stdc++.h>
using namespace std;
int k;

void combsum(int ind,int n,int target, int arr[],vector<int> &res, vector<vector<int>> &ans)
{


    if(target==0)
        {
            ans.push_back(res);
            return;
        }    
    
    for(int i = ind;i<n;i++)
    {
        if(i>ind && arr[i]==arr[i-1])   
            continue;
        if(arr[i]>target)   
            break;

        res.push_back(arr[i]);
        combsum(ind+1,n,target-arr[i],arr,res,ans);
        res.pop_back();
    }

    
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
    cout<<"Enter value of target 'k' :- ";
    cin>>k;
    if(k==0)
        {
            cout<<"{}";
            return 0;
        }

    
    cout<<"Such combinations are:-"<<endl;
    vector<int>res;
    vector<vector<int>> ans;

    sort(arr,arr+n);                //Sorting the array before hand
    combsum(0,n,k,arr,res,ans);
    for(auto it: ans)
        {
            for(auto x:it)
                cout<<x<<" ";
            cout<<endl;    
        }
    return 0;
    
}

    //Code by Blaze
    // TC O(2^n * k) and SC - changes according to ans. in general O(k * x)