// Print factorial of N


#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n == 0)
        return 1;
    return n*factorial(n-1);
}
int main()
{
    int N;
    cout<<"Enter Value of N :- ";
    cin>>N;
    if(N<0)
       {
            cout<<" No negative I/P allowed";
            return 0;
       }
    int ans=factorial(N);
    cout<<"Factorial of given number is "<<ans;
    return 0;


}
   //Code by Blaze