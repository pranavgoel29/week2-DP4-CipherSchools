#include <bits/stdc++.h>
#define MAX 10
using namespace std;


int LIP(int dp[][MAX], int mat[][MAX], int n, int m, int x, int y)
{
	
	if (dp[x][y] < 0) {
		int result = 0;

	
		if (x == n - 1 && y == m - 1)
			return dp[x][y] = 1;

	
		if (x == n - 1 || y == m - 1)
			result = 1;

		
		if(x != n-1) // x reaches last row
		if (mat[x][y] < mat[x + 1][y])
			result = 1 + LIP(dp, mat, n, m, x + 1, y);

		
		if(y != m-1) // y reaches last column
		if (mat[x][y] < mat[x][y + 1])
			result = max(result, 1 + LIP(dp, mat, n, m, x, y + 1));

		dp[x][y] = result;
	}

	return dp[x][y];
}


int wrapper(int mat[][MAX], int n, int m)
{
	int dp[MAX][MAX];
	memset(dp, -1, sizeof dp);

	return LIP(dp, mat, n, m, 0, 0);
}


int main()
{
	int mat[][MAX] = {
		{ 1, 2, 3, 4 },
		{ 2, 2, 3, 4 },
		{ 3, 2, 3, 4 },
		{ 4, 5, 6, 7 },
	};
	int n = 4, m = 4;
	cout << wrapper(mat, n, m) << endl;

	return 0;
}
