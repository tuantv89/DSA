#include <bits/stdc++.h>
using namespace std;
int matrix[505][505];
int vis[505][505];
int level[505][505];
bool is_ok(int x, int y, int n, int m)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs(queue<pair<int, int>> q, int n, int m)
{
	int row[] = {-1, 0, 0, 1};
	int col[] = {0, -1, 1, 0};
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			if (is_ok(p.first + row[k], p.second + col[k], n, m) && vis[p.first + row[k]][p.second + col[k]] == 0 && matrix[p.first + row[k]][p.second + col[k]] == 1)
			{
				q.push(make_pair(p.first + row[k], p.second + col[k]));
				vis[p.first + row[k]][p.second + col[k]] = 1;
				level[p.first + row[k]][p.second + col[k]] = level[p.first][p.second] + 1;
			}
		}
	}
}
int main()
{
	// int t;
	// cin>>t;
	// while(t--)
	//{
	int n, m;
	memset(vis, 0, sizeof(vis));
	memset(level, 0, sizeof(level));
	queue<pair<int, int>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] == 0 && matrix[i][j] == 2)
			{
				q.push(make_pair(i, j));
				vis[i][j] = 1;
			}
		}
	}
	bfs(q, n, m);
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (vis[i][j] == 0 && matrix[i][j] == 1)
			{
				f = 1;
				cout << -1 << endl;
				break;
			}
		}
		if (f == 1)
			break;
	}
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (level[i][j] > maxx)
			{
				maxx = level[i][j];
			}
		}
	}
	if (f == 0)
	{
		cout << maxx << endl;
	}
	//}
	return 0;
}
