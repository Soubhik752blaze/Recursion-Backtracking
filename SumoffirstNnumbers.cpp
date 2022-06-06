// Print Sum of first N natural numbers 


#include<bits/stdc++.h>
using namespace std;

void sumNnumbers(int i,int sum,int n)
{
    if(i>n)
        {
            cout<<sum;
            return ;
        }
    sumNnumbers(i+1,sum+i,n);  
}
int main()
{
    int N;
    cout<<"Enter Value of N :- ";
    cin>>N;
    sumNnumbers(0,0,N);
    return 0;




    //Code by Blaze

}