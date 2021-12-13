#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define M 1000000007
ll dp[100005];
int a[1005], n, k;
ll cnt()
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (i >= a[j])
				dp[i] = (dp[i] + dp[i - a[j]]) % M;
	return dp[k];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << cnt() << endl;
	}
}
