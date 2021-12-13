#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt(int n)
{
	ll res[n + 1] = {0};
	res[1] = res[0] = 1;
	res[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		res[i] = res[i - 1] + res[i - 2] + res[i - 3];
	}
	return res[n];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << cnt(n) << endl;
	}
	return 0;
}
