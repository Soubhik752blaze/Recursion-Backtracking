// Print any 1 subsequences of a string whose sum is equal to K


#include<bits/stdc++.h>
using namespace std;
int k;

bool printsubsequence(int ind,int n, int arr[], vector<int> &res,int sum)
{
    if (ind==n)
        {
            if(sum==k)
            {
                //condition satisfied
                for (auto it: res)
                    cout<<it<<" ";
                cout<<endl; 
                return true;
            }
            // condition not satisfied
            return false;
        }
    
    //take or pick the element to be in your subsequence
    res.push_back(arr[ind]);
    sum+=arr[ind];
    if(printsubsequence(ind+1,n,arr,res,sum))
        return true;
    res.pop_back();
    sum-=arr[ind];

    //Donot take or pick the element to be in your subsequence
    if(printsubsequence(ind+1,n,arr,res,sum))
        return true;

    
    return false;
    
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
    printsubsequence(0,n,arr,res,0)?cout<<"True":cout<<"False";
    return 0;
    
}

    //Code by Blaze

