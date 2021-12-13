#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000005];
ll maxx(int a[], int n)
{
	ll ans = 0;
	for (int i = 0; i < n; i++)
		dp[i] = a[i];
	dp[2] += dp[0];
	for (int i = 3; i < n; i++)
	{
		dp[i] += max(dp[i - 2], dp[i - 3]);
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << maxx(a, n) << endl;
	}
	return 0;
}
