#include <bits/stdc++.h>
using namespace std;
int mini_sw(int a[], int n)
{
	pair<int, int> p[n];
	for (int i = 0; i < n; i++)
	{
		p[i].first = a[i];
		p[i].second = i;
	}
	sort(p, p + n);
	vector<bool> check(n, false);
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (check[i] || p[i].second == i)
			continue;
		int c = 0;
		int j = i;
		while (!check[j])
		{
			check[j] = 1;
			j = p[j].second;
			c++;
		}
		if (c > 0)
			res += (c - 1);
	}
	return res;
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
		cout << mini_sw(a, n) << endl;
	}
	return 0;
}
