#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1005][1005], truoc[1005];
void bfs(int u)
{
	truoc[u] = u;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (a[v][i] && !truoc[i])
			{
				truoc[i] = v;
				q.push(i);
			}
		}
	}
}

int main()
{
	int t, u, v;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(truoc, 0, sizeof(truoc));
		cin >> N >> M >> u >> v;
		int x, y;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		bfs(u);
		if (truoc[v] == 0)
			cout << -1 << endl;
		else
		{
			int cnt = 1;
			while (truoc[v] != u)
			{
				cnt++;
				v = truoc[v];
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
