#include <bits/stdc++.h>
using namespace std;
int dp[10005];
void mini()
{
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= 10000; i++)
	{
		dp[i] = i;
		for (int j = 1; j <= 10000; j++)
		{
			int temp = j * j;
			if (temp > i)
				break;
			dp[i] = min(dp[i], 1 + dp[i - temp]);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	mini();
	while (t--)
	{
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}
