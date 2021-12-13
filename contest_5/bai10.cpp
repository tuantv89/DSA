#include <bits/stdc++.h>
using namespace std;
#define Max 505
int a[Max][Max], c[Max][Max], m, n;
int minicost()
{
	memset(c, 0, sizeof(c));
	c[1][1] = a[1][1];
	for (int i = 1; i <= n; i++)
		c[i][1] = c[i - 1][1] + a[i][1];
	for (int i = 1; i <= m; i++)
		c[1][i] = c[1][i - 1] + a[1][i];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			c[i][j] = min(c[i - 1][j], min(c[i][j - 1], c[i - 1][j - 1])) + a[i][j];
		}
	}
	return c[n][m];
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		}
		cout << minicost() << endl;
	}
	return 0;
}
