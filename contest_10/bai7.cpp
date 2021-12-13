#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[100005];
vector<vector<int>> ke(100005);
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
			}
		}
	}
}
bool check()
{
	for (int i = 1; i <= N; i++)
		if (!vis[i])
			return false;
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		ke.clear();
		cin >> N >> M;
		ke.resize(N + 5);
		for (int i = 1; i <= M; i++)
		{
			int u, v;
			cin >> u >> v;
			ke[u].push_back(v);
			ke[v].push_back(u);
		}
		bfs(1);
		if (check())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
