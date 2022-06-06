// Print Nth Fibonaaci number


#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-1)+fib(n-2);
    
}
int main()
{
    int N;
    cout<<"Enter Value of N :- ";
    cin>>N;
    if(N<0)
       {
            cout<<"wrong Input";
            return 0;
       }
    int ans=fib(N);
    cout<<"Nth fibonacci number is "<<ans;
    return 0;


}

    //Code by Blaze

