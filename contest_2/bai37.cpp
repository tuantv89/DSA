#include <bits/stdc++.h>
using namespace std;
int m, n, ans;
int check[25][25];
void solve(int u, int tmp)
{
	ans = max(ans, tmp);
	for (int v = 0; v < n; v++)
	{
		if (check[u][v] == 1)
		{
			check[u][v] = 0;
			check[v][u] = 0;
			solve(v, tmp + 1);
			check[u][v] = 1;
			check[v][u] = 1;
		}
	}
}
void handle()
{
	cin >> n >> m;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		check[u][v] = 1;
		check[v][u] = 1;
	}
	ans = -1;
	for (int i = 0; i < n; i++)
	{
		solve(i, 0);
	}
	cout << ans << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		handle();
	}
}
