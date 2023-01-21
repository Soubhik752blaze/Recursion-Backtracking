// Print the Kth permutation wise sequence.

#include<bits/stdc++.h>
using namespace std;

string kthpermutationsequence(int n, int k)
{
    int fact=1;
    vector<int> numbers;
    for(int i=1;i<n;i++)
    {
        fact=fact*i;
        numbers.push_back(i);
    }
    string ans = "";
    numbers.push_back(n);
    k=k-1;
    while(true)
    {
        //takes the starting number and then removes it for further iterations
        ans = ans + to_string(numbers[k / fact ]);
        numbers.erase(numbers.begin() + k / fact );

        //if no numbers left then we have the answer
        if(numbers.size()==0)
            break;

        //modifications for next iteration
        k = k % fact;
        fact = fact / numbers.size();   
    }
    return ans;
}
int main()
{
    int n,k;
    cout<<"Enter the value of n:- ";
    cin>>n;
    cout<<"Ok the numbers sequence on which permutations will be performed is :- ";
    for(int i=1;i<n+1;i++)
        cout<<i<<" ";

    cout<<endl<<"Enter the value of k:- ";
    cin>>k;
    string ans = kthpermutationsequence(n,k);
    cout<<"The required sequence is :- "<<ans;
    return 0;
}

    //Code by Blaze     TC(n)= o(n^2) if no storage need(only print) and SC(n)= o(n)
                        

