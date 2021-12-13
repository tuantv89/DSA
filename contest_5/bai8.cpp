#include <bits/stdc++.h>
using namespace std;
#define M 505
int mt[M][M], a[M][M];
int maxx(int a[M][M], int n, int m)
{
	int ans = 0;
	memset(mt, 0, sizeof(mt));
	for (int i = 0; i < n; i++)
		mt[i][0] = a[i][0];
	for (int i = 0; i < m; i++)
		mt[0][i] = a[0][i];
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (a[i][j] == 1)
			{
				mt[i][j] = min(min(mt[i - 1][j], mt[i][j - 1]), mt[i - 1][j - 1]) + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mt[i][j] > ans)
				ans = mt[i][j];
		}
	}
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
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		cout << maxx(a, n, m) << endl;
	}
	return 0;
}
