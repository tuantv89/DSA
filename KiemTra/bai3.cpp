#include <bits/stdc++.h>
using namespace std;
int dp[100005];
int mini(int n)
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i == 2 || i == 3)
			dp[i] = i;
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}
	return dp[n];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << mini(n) << endl;
	}
	return 0;
}
