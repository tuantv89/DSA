#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000
typedef long long ll;
int N;
ll M;
ll f[100005];
vector<pair<int, ll>> ke[100005];
ll d[100005];
int vis[100005];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
void Dijkstra()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		d[i] = INF;
	memset(vis, 0, sizeof(vis));
	for (ll i = 1; i <= M; i++)
	{
		int u, v;
		ll c;
		cin >> u >> v >> c;
		ke[u].push_back({v, c});
		ke[v].push_back({u, c});
	}
	d[1] = 0;
	for (int i = 1; i <= N; i++)
		f[i] = 0;
	f[1] = 1;
	pq.push({0, 1});
	while (!pq.empty())
	{
		pair<ll, ll> tmp = pq.top();
		pq.pop();
		int u = tmp.second;
		ll Min = tmp.first;
		// vis[u]=1;
		for (int i = 0; i < ke[u].size(); i++)
		{
			int v = ke[u][i].first;
			ll c = ke[u][i].second;
			// if(!vis[v])
			//{
			if (d[v] == Min + c)
			{
				f[v] += f[u];
				continue;
			}
			if (d[v] > Min + c)
			{
				f[v] = f[u];
				d[v] = Min + c;
				pq.push({d[v], v});
			}
			//}
		}
	}
	cout << d[N] << " " << f[N];
}
int main()
{
	Dijkstra();
	return 0;
}
