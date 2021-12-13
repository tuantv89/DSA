#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		ll sum = 0;
		for (ll i = 0; i < n - 1; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		ll tmp = (n * (n + 1)) / 2;
		cout << tmp - sum << endl;
	}
	return 0;
}
