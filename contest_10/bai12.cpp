#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
void Prim()
{
	cin >> N >> M;
	int u, v, c;
	vector<pair<int, int>> ke[N + 5];
	for (int i = 1; i <= M; i++)
	{
		cin >> u >> v >> c;
		ke[u].push_back({c, v});
		ke[v].push_back({c, u});
	}
	int vis[N + 5];
	memset(vis, 0, sizeof(vis));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	for (int i = 0; i < ke[1].size(); i++)
	{
		c = ke[1][i].first;
		v = ke[1][i].second;
		pq.push({
			c,
			{1, v},
		});
	}
	vis[1] = 1;
	int cnt = 0;
	ll Min = 0;
	while (cnt < N - 1)
	{
		pair<int, pair<int, int>> tmp = pq.top();
		pq.pop();
		c = tmp.first;
		u = tmp.second.first;
		v = tmp.second.second;
		if ((vis[u] == 0 && vis[v] == 0) || (vis[u] == 1 && vis[v] == 1))
			continue;
		else
		{
			cnt++;
			Min += c;
			vis[u] = 1;
			vis[v] = 1;
			for (int i = 0; i < ke[v].size(); i++)
			{
				c = ke[v][i].first;
				u = ke[v][i].second;
				if (vis[u] == 0)
					pq.push({
						c,
						{v, u},
					});
			}
		}
	}
	cout << Min << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Prim();
	}
	return 0;
}
