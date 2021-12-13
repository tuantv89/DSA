#include <bits/stdc++.h>
using namespace std;
int Count(int x, int b[], int m, int dem[])
{
	if (x == 0)
		return 0;
	if (x == 1)
		return dem[0];
	int *idx = upper_bound(b, b + m, x);
	int ans = (b + m) - idx;
	ans += dem[0] + dem[1];
	if (x == 2)
		ans -= (dem[3] + dem[4]);
	if (x == 3)
		ans += dem[2];
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int a[n], b[m], dem[5] = {0};
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
			if (b[i] < 5)
				dem[b[i]]++;
		}
		sort(b, b + m);
		int res = 0;
		for (int i = 0; i < n; i++)
			res += Count(a[i], b, m, dem);
		cout << res << endl;
	}
	return 0;
}
