#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<pair<int, int>, int>> edges;
void BellmanFord(int x)
{
	vector<int> d(N + 5, INT_MAX);
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
		{
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (d[i] == INT_MAX)
			cout << "INFI"
				 << " ";
		else
			cout << d[i] << " ";
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	int x;
	while (t--)
	{
		edges.clear();
		cin >> N >> M >> x;
		int u, v, c;
		for (int i = 1; i <= M; i++)
		{
			cin >> u >> v >> c;
			edges.push_back({{u, v}, c});
		}
		BellmanFord(x);
	}
	return 0;
}
