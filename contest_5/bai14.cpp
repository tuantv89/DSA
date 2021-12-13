#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int LRS(string s, int n)
{
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s[i - 1] == s[j - 1] && i != j)
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][n];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << LRS(s, n) << endl;
	}
	return 0;
}
