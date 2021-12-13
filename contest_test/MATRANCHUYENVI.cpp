#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	int dem = 1;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		ll a[n][m], b[m][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				b[i][j] = a[j][i];
		ll c[n][n];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				c[i][j] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < m; k++)
					c[i][j] += (a[i][k] * b[k][j]);
			}
		}
		cout << "Test " << dem << ":" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << c[i][j] << " ";
			cout << endl;
		}
		dem++;
	}
	return 0;
}
