/*Question :-Given an integer array nums,
return all the different possible non-decreasing subsequences of the given array with at least two elements.
You may return the answer in any order.*/

#include <bits/stdc++.h>
using namespace std;

// Entire problem is based on 1 concept:- Take an element or Dont take it.
// Take an element into consideration, if its greater than the last element inserted in temp or its the first element to be inserted in temp.
// Dont take if this criteria is not met.
void helper(int ind, int n, vector<int> nums, set<vector<int>> &st, vector<int> &temp)
{
    // base condition
    if (ind >= n)
    {
        if (temp.size() > 1)
            st.insert(temp);
        return;
    }

    // take
    if (temp.size() == 0 || nums[ind] >= temp.back())
    {
        temp.push_back(nums[ind]);
        // cout << nums[ind] << " ";
        helper(ind + 1, n, nums, st, temp);
        temp.pop_back();
    }

    // not take
    helper(ind + 1, n, nums, st, temp);
}

// Intuition :- Subsequences involved problems in 90% cases have chances of having either recursion and backtracking involved. or DP involved.
vector<vector<int>> findSubsequences(vector<int> nums)
{
    int n = nums.size();
    vector<int> temp;
    set<vector<int>> st;
    helper(0, n, nums, st, temp);
    vector<vector<int>> ans;
    for (auto it : st)
        ans.push_back(it);
    return ans;
}
int main()
{
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> ans = findSubsequences(nums);
    for (auto x : ans)
    {
        cout << "[ ";
        for (auto it : x)
            cout << it << " ";
        cout << "]";
    }
}

// TC -> O(2^n)
// SC -> O(2N)