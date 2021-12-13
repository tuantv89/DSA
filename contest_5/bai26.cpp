#include <bits/stdc++.h>
using namespace std;
int dp[105][25005];
int w[105];
int maxx(int w[], int C, int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= C; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (j >= w[i - 1])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + w[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][C];
}
int main()
{
	int C, n;
	cin >> C >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	cout << maxx(w, C, n);
	return 0;
}
