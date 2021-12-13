#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
typedef long long ll;
ll res[100005];
ll cnt(int n, int k)
{
	res[0] = 1;
	res[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		res[i] = 0;
		for (int j = 1; j <= i && j <= k; j++)
			res[i] = (res[i] + res[i - j]) % m;
	}
	return res[n];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << cnt(n, k) << endl;
	}
	return 0;
}
