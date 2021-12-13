#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int N, M;
int d[105][105];
void Floyd()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}
int main()
{
	cin >> N >> M;
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
		int u, v, c;
		cin >> u >> v >> c;
		d[u][v] = c;
		d[v][u] = c;
	}
	Floyd();
	int Q;
	cin >> Q;
	while (Q--)
	{
		int u, v;
		cin >> u >> v;
		cout << d[u][v] << endl;
	}
	return 0;
}
