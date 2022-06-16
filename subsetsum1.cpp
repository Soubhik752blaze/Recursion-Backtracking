/*Subset sum problem is to find subset of elements that are selected from a given set whose sum adds up to a given number K. 
We are considering the set contains non-negative values. 
It is assumed that the input set is unique (no duplicates are presented).*/

#include<bits/stdc++.h>
using namespace std;


void subsum(int ind,int n,int sum, int arr[], vector<int> &ans)
{   
    if(ind==n)
        {
            ans.push_back(sum);
            return;
        }
    //picks the element and hence sum increased and also since chance of picking it up again so index not increased
    subsum(ind+1,n,sum+arr[ind],arr,ans);
    
    //Doesnot pick the element and hence sum not increased and also index + 1
    subsum(ind+1,n,sum,arr,ans);
    
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

    
    cout<<"Such combinations :-"<<endl;
    vector<int> res;
    vector<int> ans;
    subsum(0,n,0,arr,ans);
    sort(ans.begin(), ans.end());
    for(auto x: ans)
        {
            cout<<x<<" ";
                
        }
    return 0;
    
}

    //Code by Blaze
    /* Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.*/