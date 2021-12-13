#include <bits/stdc++.h>
using namespace std;
int N, M, z, t;
int vis[1005];
vector<vector<int>> ke(1005);
bool ok(int a, int b)
{
	if ((a == z && b == t) || (a == t && b == z))
		return false;
	return true;
}
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
			if (vis[ke[t][i]] == 0 && ok(t, ke[t][i]))
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
		if (vis[i] == 0)
			return false;
	return true;
}
int main()
{
	int tests, u, x, y;
	cin >> tests;
	while (tests--)
	{
		ke.clear();
		cin >> N >> M;
		ke.resize(N + 1);
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		vector<pair<int, int>> res;
		for (int i = 1; i <= N; i++)
			sort(ke[i].begin(), ke[i].end());
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < ke[i].size(); j++)
			{
				if (i < ke[i][j])
				{
					memset(vis, 0, sizeof(vis));
					z = i;
					t = ke[i][j];
					bfs(1);
					if (check() == false)
						res.push_back(make_pair(i, ke[i][j]));
				}
			}
		}
		for (int i = 0; i < res.size(); i++)
			cout << res[i].first << " " << res[i].second << " ";
		cout << endl;
	}
	return 0;
}
