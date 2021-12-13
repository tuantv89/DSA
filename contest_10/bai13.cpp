#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<pair<int, int>, int>> edges;
bool ChuTrinhAmFord(int x, int d[])
{
	for (int i = 1; i <= N; i++)
		d[i] = INT_MAX;
	d[x] = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int u = edges[j].first.first;
			int v = edges[j].first.second;
			int c = edges[j].second;
			if (d[u] != INT_MAX && d[u] + c < d[v])
				d[v] = d[u] + c;
		}
	}
	for (int j = 0; j < edges.size(); j++)
	{
		int u = edges[j].first.first;
		int v = edges[j].first.second;
		int c = edges[j].second;
		if (d[u] != INT_MAX && d[u] + c < d[v])
			return true;
	}
	return false;
}
bool NegativeCycle()
{
	int vis[1005];
	int d[N + 5];
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= N; i++)
	{
		if (!vis[i])
		{
			if (ChuTrinhAmFord(i, d))
				return true;
			for (int j = 1; j <= N; j++)
			{
				if (d[i] != INT_MAX)
					vis[i] = 1;
			}
		}
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		edges.clear();
		cin >> N >> M;
		int u, v, c;
		for (int i = 1; i <= M; i++)
		{
			cin >> u >> v >> c;
			edges.push_back({{u, v}, c});
		}
		if (NegativeCycle())
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
