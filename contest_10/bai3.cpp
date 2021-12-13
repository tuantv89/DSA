#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> ke[1005];
int color[1005];
bool is_ok(int i)
{
	color[i] = 1;
	queue<int> q;
	q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int j = 0; j < ke[u].size(); j++)
		{
			if (ke[u][j] == u)
				return false;
			if (color[ke[u][j]] == -1)
			{
				color[ke[u][j]] = 1 - color[u];
				q.push(ke[u][j]);
			}
			else if (color[u] == color[ke[u][j]])
				return false;
		}
	}
	return true;
}
void solve()
{
	for (int i = 0; i <= 1000; i++)
		ke[i].clear();
	memset(color, -1, sizeof(color));
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int u, v;
		cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		if (color[i] == -1)
		{
			if (!is_ok(i))
			{
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
