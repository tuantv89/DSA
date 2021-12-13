#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum(string s)
{
	int n = s.length();
	ll dp[n];
	dp[0] = (s[0] - '0');
	ll ans = dp[0];
	for (int i = 1; i < n; i++)
	{
		int tmp = int(s[i] - '0');
		dp[i] = (i + 1) * tmp + 10 * dp[i - 1];
		ans += dp[i];
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << sum(s) << endl;
	}
	return 0;
}
