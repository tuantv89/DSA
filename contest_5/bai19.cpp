#include <bits/stdc++.h>
using namespace std;
int mini_time(int n, int x, int y, int z) // x:insert, y:remove, z:copy
{
	if (n == 0)
		return 0;
	if (n == 1)
		return x;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[1] = x;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			dp[i] = min(dp[i - 1] + x, dp[i / 2] + z);
		else
			dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + z + y);
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
		int x, y, z;
		cin >> x >> y >> z;
		cout << mini_time(n, x, y, z) << endl;
	}
	return 0;
}
