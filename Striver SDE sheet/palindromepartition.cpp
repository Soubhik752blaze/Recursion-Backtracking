/* Question:- Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.*/

#include <bits/stdc++.h>
using namespace std;

// function to check if a string is pallindrome
bool isPalindrome(string s, int start, int end)
{
	while (start <= end)
	{
		if (s[start++] != s[end--])
			return false;
	}
	return true;
}

// Approach -> check at every partition if pallindrome is possible or not
// if pallindrome is possible, put it into path vector and check for the rest of the string..
// if a solution not found ultimately down the road, then back-track the steps and look for other possibilities.
void func(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
	// base-case -> if reached the end of string, means a proper pallindrome partition is done.
	if (index == s.size())
	{
		res.push_back(path);
		return;
	}

	// loop for all the indices and check if pallindrome is possible,
	// if yes, take it in "path", and then look for same pallindrome partitions in the rest of the string(i+1)
	for (int i = index; i < s.size(); i++)
	{
		// take if pallindrome possible
		if (isPalindrome(s, index, i))
		{
			path.push_back(s.substr(index, i - index + 1));
			func(i + 1, s, path, res);
			path.pop_back(); // backtracking step
		}

		// not take option not there since, here we cant skip anything (not subsequences)
	}
}
vector<vector<string>> palindromepartitioning(string s)
{
	vector<vector<string>> res;
	vector<string> path;
	func(0, s, path, res);
	return res;
}

int main()
{
	string s = "aabb";
	vector<vector<string>> ans = palindromepartitioning(s);
	for (auto x : ans)
	{	
		cout << "[ ";
		for (auto str : x)
			cout << str << " ";
		cout << "] "<<endl;
	}
}

/*Time Complexity: O((2^n) * k * (n/2) )
Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome.
O(k) is for inserting the palindromes in another data structure, where k is the average length of the palindrome list.

Space Complexity: O(k * x)
Reason: The space complexity can vary depending upon the length of the answer.
k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer.
The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/