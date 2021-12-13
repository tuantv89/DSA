#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005];
vector<vector<int>> ke(1005);
void bfs(int u)
{
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		cout << t << " ";
		for (int i = 0; i < ke[t].size(); i++)
		{
			if (vis[ke[t][i]] == 0)
			{
				vis[ke[t][i]] = 1;
				q.push(ke[t][i]);
			}
		}
	}
	cout << endl;
}
int main()
{
	int t, u, x, y;
	cin >> t;
	while (t--)
	{
		ke.clear();
		memset(vis, 0, sizeof(vis));
		cin >> N >> M >> u;
		ke.resize(N + 1);
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		bfs(u);
	}
	return 0;
}
