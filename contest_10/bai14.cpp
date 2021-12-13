#include <bits/stdc++.h>
using namespace std;
#define INF 1000005
int N, M, x;
void Dijkstra()
{
	cin >> N >> M >> x;
	int u, v, c;
	vector<pair<int, int>> ke[N + 5];
	int vis[N + 5];
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= M; i++)
	{
		cin >> u >> v >> c;
		ke[u].push_back({v, c});
		ke[v].push_back({u, c});
	}
	vector<int> d(N + 5, INF);
	d[x] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, x});
	while (!pq.empty())
	{
		pair<int, int> tmp = pq.top();
		pq.pop();
		int u = tmp.second;
		vis[u] = 1;
		for (int i = 0; i < ke[u].size(); i++)
		{
			v = ke[u][i].first;
			c = ke[u][i].second;
			if (!vis[v])
			{
				if (d[v] > d[u] + c)
				{
					d[v] = d[u] + c;
					pq.push({d[v], v});
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
		cout << d[i] << " ";
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Dijkstra();
	}
	return 0;
}
