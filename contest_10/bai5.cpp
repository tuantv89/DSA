#include <bits/stdc++.h>
using namespace std;
int N, K, M;
vector<pair<int, int>> v;
int vis[105][105];
set<pair<pair<int, int>, pair<int, int>>> check;
bool ok(int x, int y)
{
	return (x >= 1 && x <= N && y >= 1 && y <= N);
}
void bfs(pair<int, int> u)
{
	queue<pair<int, int>> q;
	q.push(u);
	vis[u.first][u.second] = 1;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			pair<int, int> tmp = q.front();
			q.pop();
			int x = tmp.first, y = tmp.second;
			if (ok(x + 1, y) && check.find(make_pair(tmp, make_pair(x + 1, y))) == check.end())
			{
				if (vis[x + 1][y] == 0)
				{
					vis[x + 1][y] = 1;
					q.push({x + 1, y});
				}
			}
			if (ok(x - 1, y) && check.find(make_pair(tmp, make_pair(x - 1, y))) == check.end())
			{
				if (vis[x - 1][y] == 0)
				{
					vis[x - 1][y] = 1;
					q.push({x - 1, y});
				}
			}
			if (ok(x, y + 1) && check.find(make_pair(tmp, make_pair(x, y + 1))) == check.end())
			{
				if (vis[x][y + 1] == 0)
				{
					vis[x][y + 1] = 1;
					q.push({x, y + 1});
				}
			}
			if (ok(x, y - 1) && check.find(make_pair(tmp, make_pair(x, y - 1))) == check.end())
			{
				if (vis[x][y - 1] == 0)
				{
					vis[x][y - 1] = 1;
					q.push({x, y - 1});
				}
			}
		}
	}
}

int main()
{
	cin >> N >> K >> M;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= M; i++)
	{
		int x, y, z, t;
		cin >> x >> y >> z >> t;
		check.insert({{x, y}, {z, t}});
		check.insert({{z, t}, {x, y}});
	}
	for (int i = 1; i <= K; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		memset(vis, 0, sizeof(vis));
		bfs(v[i]);
		for (int j = 0; j < v.size(); j++)
		{
			if (vis[v[j].first][v[j].second] == 0)
				ans++;
		}
	}
	cout << ans / 2;
	return 0;
}
