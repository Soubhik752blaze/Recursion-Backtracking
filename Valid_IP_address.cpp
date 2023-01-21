/*Question:- A valid IP address consists of exactly four integers separated by single dots.
Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s.
You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.*/

#include <bits/stdc++.h>
using namespace std;


bool check(string s)
{

    if (s.size() == 1)
        return true;

    // cant be leading zeroes
    if (s.size() > 1 && s[0] == '0')
        return false;

    // number should be in range of 0 to 255
    int num = stoi(s);
    if (num > 255)
        return false;
    return true;
}
void helper(int i, int part, string s, string temp, vector<string> &ans)
{
    // base conditions :-
    //  if 4 parts of IP is made AND the string "s" is completely traversed as well.
    //  if either 4 parts of IP is made OR the string "s" is completely traversed.
    int n = s.size();
    if (part == 4 && i == n)
        ans.push_back(temp.substr(0, temp.size() - 1));
    if (part == 4 || i == n)
        return;

    // recursive part
    helper(i + 1, part + 1, s, temp + s[i] + ".", ans);
    if (s.size() > i + 1 && check(s.substr(i, 2)))
        helper(i + 2, part + 1, s, temp + s.substr(i, 2) + ".", ans);
    if (s.size() > i + 2 && check(s.substr(i, 3)))
        helper(i + 3, part + 1, s, temp + s.substr(i, 3) + ".", ans);
}
vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;
    // impossible case
    if (s.size() < 4 || s.size() > 12)
        return ans;

    string temp;
    helper(0, 0, s, temp, ans);
    return ans;
}

int main()
{
    string s = "101023";
    vector<string> ans = restoreIpAddresses(s);
    cout<< "The Valid IP addresses possible from the given string are :- "<<endl;
    for(auto str : ans)
        cout << str <<endl;
}