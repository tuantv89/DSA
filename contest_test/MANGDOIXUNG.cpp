#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int check(int n, ll a[])
{
	if (n == 1)
		return 1;
	int s = 0, q = n - 1;
	while (s <= q)
	{
		if (a[s] == a[q])
		{
			s++;
			q--;
		}
		else
		{
			return 0;
			break;
		}
	}
	return 1;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (check(n, a) == 1)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}
