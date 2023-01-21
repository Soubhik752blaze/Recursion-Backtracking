/*Subset sum problem is to find all possible subset sum of elements that are selected from a given array.
We are considering the set contains non-negative values.
It is assumed that the input set is unique (no duplicates are presented).*/

#include <bits/stdc++.h>
using namespace std;

//Set A is said to be a subset of Set B if all the elements of Set A are also present in Set B. 
//In other words, set A is contained inside Set B.
void subsetsum(int ind, int n, int sum, vector<int> arr, vector<int> &ans)
{
    //base case where ind goes out of bound.
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }
    // picks the element and hence sum increased and also since chance of picking it up again so index not increased
    subsetsum(ind + 1, n, sum + arr[ind], arr, ans);

    // Doesnot pick the element and hence sum not increased and also index + 1
    subsetsum(ind + 1, n, sum, arr, ans);
}
int main()
{
    vector<int> arr = {5, 2, 1};
    int n = 3;
    cout << "Such combinations :-" << endl;
    vector<int> res;
    vector<int> ans;
    subsetsum(0, n, 0, arr, ans);
    sort(ans.begin(), ans.end()); // optional -> if we want the ans in increasing order
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}

/* Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.*/