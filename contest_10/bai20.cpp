#include <bits/stdc++.h>
using namespace std;
#define INF 100000
typedef double db;
int N, M;
void solve()
{
	cin >> N >> M;
	int d[N + 5][N + 5];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		d[u][v] = 1;
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	db cnt = 0, sum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j && d[i][j] != INF)
			{
				sum += d[i][j];
				cnt++;
			}
		}
	}
	double ans = (double)(sum / cnt);
	cout << fixed << setprecision(2) << ans << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
