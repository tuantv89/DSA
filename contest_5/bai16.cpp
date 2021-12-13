#include <bits/stdc++.h>
using namespace std;
int a[1005], c[1005], n;
int qhd(int a[])
{
	for (int i = 1; i <= n; i++)
		c[i] = a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i])
			{
				c[i] = max(c[i], c[j] + a[i]);
			}
		}
		ans = max(ans, c[i]);
	}
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		cout << qhd(a) << endl;
	}
	return 0;
}
