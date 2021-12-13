#include <bits/stdc++.h>
using namespace std;
int cnt(int m, int n)
{
	if (m == 1 || n == 1)
		return 1;
	return cnt(m - 1, n) + cnt(m, n - 1);
}
int main()
{
	int t;
	int m, n;
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		int a[m][n];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		cout << cnt(m, n) << endl;
	}
	return 0;
}
