#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int max_len_dx(string s)
{
	int ans = 1, n = s.length();
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = 1;
			ans = 2;
		}
	}
	for (int k = 3; k <= n; k++)
	{
		for (int i = 0; i < n - k + 1; i++)
		{
			int j = i + k - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1])
			{
				dp[i][j] = 1;
				ans = max(ans, k);
			}
		}
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		cin >> s;
		cout << max_len_dx(s) << endl;
	}
	return 0;
}
