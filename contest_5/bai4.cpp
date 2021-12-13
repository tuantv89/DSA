#include <bits/stdc++.h>
using namespace std;
#define inf 100000007
int n, k, s = 0, dp[1005][55], a[1005];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		s = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] %= k;
			s = (s + a[i]) % k;
		}
		memset(dp, inf, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				int r = (j - a[i] + k) % k;
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][r] + 1);
			}
		}
		cout << n - dp[n][s % k] << endl;
	}
	return 0;
}
