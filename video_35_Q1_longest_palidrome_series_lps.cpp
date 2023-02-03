#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int n;
int lps(string& s, int n1, int n2)
{
	if (n1 == 0 || n2 == 0) {
		return 0;
	}
	if (dp[n1][n2] != -1) {
		return dp[n1][n2];
	}
	
	if (s[n1 - 1] == s[n - n2]) {
		return dp[n1][n2] = 1 + lps(s, n1 - 1, n2 - 1);
	}
	else {
		return dp[n1][n2] = max(lps(s, n1 - 1, n2),
								lps(s, n1, n2 - 1));
	}
}

int main()
{
	string s = "GEEKSFORGEEKS";
	n = s.size();
	dp[n][n];
	memset(dp, -1, sizeof(dp));
	cout << "The length of the LPS is " << lps(s, n, n) << endl;
	return 0;
}
