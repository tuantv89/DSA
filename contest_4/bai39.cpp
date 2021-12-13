#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int find(ll a[], ll b[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] != b[i])
			return i + 1;
	}
	return n;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll a[n], b[n - 1];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n - 1; i++)
			cin >> b[i];
		cout << find(a, b, n) << endl;
	}
	return 0;
}
