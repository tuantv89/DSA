#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1005][1005], vis[1005];
vector<pair<int, int>> res;
void bfs(int u)
{
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (a[v][i] && !vis[i])
			{
				vis[i] = 1;
				q.push(i);
				res.push_back({v, i});
				if (res.size() == N - 1)
					return;
			}
		}
	}
}

int main()
{
	int t, u;
	cin >> t;
	while (t--)
	{
		res.clear();
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		cin >> N >> M >> u;
		int x, y;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		bfs(u);
		if (res.size() < N - 1)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < res.size(); i++)
				cout << res[i].first << " " << res[i].second << endl;
		}
	}
	return 0;
}
