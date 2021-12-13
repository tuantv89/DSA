#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005];
vector<int> ke[1005];
vector<pair<int, int>> res;
void bfs(int u)
{
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < ke[t].size(); i++)
		{
			if (!vis[ke[t][i]])
			{
				vis[ke[t][i]] = 1;
				q.push(ke[t][i]);
				res.push_back({t, ke[t][i]});
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
		for (int i = 0; i <= 1000; i++)
			ke[i].clear();
		memset(vis, 0, sizeof(vis));
		cin >> N >> M >> u;
		int x, y;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
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
