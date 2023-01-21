


#include<bits/stdc++.h>
using namespace std;


void reversearray(int l,int r,int arr[])
{
    if(l>=r)
        return;
    swap(arr[l],arr[r]);
    reversearray(l+1,r-1,arr);
}
int main()
{
    int N;
    cout<<"Enter Value of N :- ";
    cin>>N;
    if(N<=1)
       {
            cout<<" No neverse possible";
            return 0;
       }
    int arr[N];
    cout<<"Enter Values of array ---> ";
    for(int i=0;i<N;i++)
        cin>>arr[i];
    
    reversearray(0,N-1,arr);
    for(int i=0;i<N;i++)
        cout<<arr[i]<<" ";
    return 0;

}


    //Code by Blaze

