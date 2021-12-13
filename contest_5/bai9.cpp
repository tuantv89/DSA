#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
ll dp[105][50005];
ll count(int n, int sum)
{
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= sum; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= sum && i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				if (j >= k)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % M;
			}
		}
	}
	return dp[n][sum];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, sum;
		cin >> n >> sum;
		cout << count(n, sum) << endl;
	}
	return 0;
}
