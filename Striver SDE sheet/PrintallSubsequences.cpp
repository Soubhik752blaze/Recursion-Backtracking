// Question:-  Print all subsequences of a string


#include<bits/stdc++.h>
using namespace std;

void printsubsequence(int ind,int n, int arr[], vector<int> &res)
{
    if (ind==n)
        {
            for(auto it: res)
                cout<<it<<" ";
            if(res.size()==0)
                cout<<"{}";
            cout<<endl;
            return;
        }
    
    //take or pick the element to be in your subsequence
    res.push_back(arr[ind]);
    printsubsequence(ind+1,n,arr,res);
    res.pop_back();

    //Donot take or pick the element to be in your subsequence
    printsubsequence(ind+1,n,arr,res);
    
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 5;
    cout<<"The subsequences are:- "<<endl;
    vector<int> res;
    printsubsequence(0,n,arr,res);
    


}

    //Code by Blaze

