// Print Sum of first N natural numbers 


#include<bits/stdc++.h>
using namespace std;

void sumNnumbers(int i,int sum)
{
    if(i<1)
        {
            cout<<sum;
            return ;
        }
    sumNnumbers(i-1,sum+i);  
}
int main()
{
    int N;
    cout<<"Enter Value of N :- ";
    cin>>N;
    sumNnumbers(N,0);
    return 0;




    //Code by blaze

}