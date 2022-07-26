/*Given an array of positive integers arr[] which may contain duplicate entries, find all possible subsets in arr[]. 
The solution shouldnot contain duplicate entries os subsets.*/

#include<bits/stdc++.h>
using namespace std;
int k;

void subsum(int ind,int n, int arr[],vector<int> &res, vector<vector<int>> &ans)
{
    ans.push_back(res);
    for(int i = ind;i<n;i++)
    {
        if(i>ind && arr[i]==arr[i-1])   
            continue;

        res.push_back(arr[i]);
        subsum(i+1,n,arr,res,ans);
        res.pop_back();
    }
/*here not added or not selected function isnot there, since we are already checking,
for arr[i]!=arr[i-1]
*/
    
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
    
    cout<<"Such combinations are :-"<<endl;
    vector<int>res ;
    vector<vector<int>> ans;

    sort(arr,arr+n);           
    subsum(0,n,arr,res,ans);
    for(auto it: ans)
        {
            if(it.size()==0)
                cout<<"[]";

            else
            {        
                for(auto x:it)
                    cout<<x<<" ";
            }
            cout<<endl;    
        }
    return 0;
    
}


    //Code by Blaze
    // TC O(2^n * k) and SC -  O(2^n * k)