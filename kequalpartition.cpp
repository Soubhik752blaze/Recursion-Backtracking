/*Question :- Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.*/


#include<bits/stdc++.h>
using namespace std;
bool help(vector<int> &nums,int ind, int currsum,int sum, int k, vector<int> &vis)
{
    if(k==0) return true;
    if(currsum>sum) return false;
    if(currsum == sum)
        return help(nums,ind,currsum,sum,k-1,vis);
    
    for(int i=ind;i<nums.size();i++)
    {
        if(vis[ind])    continue;
        vis[ind]=1;         //backtracking
        if(help(nums,ind,currsum+nums[i],sum,k,vis))
            return true;
        vis[ind]=0;         //backtracking
    }
    return false;             
    
}

bool kequalsubsetsum( vector<int> &nums, int k)
{
    int sum=0;
    for(auto it:nums)
        sum+=it;
    if(sum % k)
        return false;
    int target=sum/k;
    if(nums.size()<k)
        return false;
    vector<int> vis(nums.size(),0);
    help(nums,0,0,k,target,vis);
}
int main()
{
    vector<int> nums = {4,3,2,1,5,3,2,6,-1};
    int k = 5;
    if(kequalsubsetsum(nums,k))
        cout<<"Yes";
    else
        cout<<"no";
    return 0;
    
}

    //Code by Blaze
    //TC-->O(k*2^n)
    //SC-->O(n)