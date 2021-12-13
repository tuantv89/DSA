#include <bits/stdc++.h>
using namespace std;
int N, M;
char c[505][505];
int vis[505][505];
pair<int, int> S, T;
int is_possible()
{
	queue<pair<int, int>> q;
	q.push(S);
	int Max = -1;
	vis[S.first][S.second] = 1;
	while (!q.empty())
	{
		Max++;
		if (Max > 2)
			return 0;
		int size = q.size();
		while (size--)
		{
			pair<int, int> tmp = q.front();
			q.pop();
			int x = tmp.first, y = tmp.second;
			for (int i = x - 1; i >= 1; i--)
			{
				if (c[i][y] == '*')
					break;
				else
				{
					pair<int, int> temp = {i, y};
					if (temp == T)
						return 1;
					if (vis[i][y] == 0)
					{
						vis[i][y] = 1;
						q.push({i, y});
					}
				}
			}
			for (int i = x + 1; i <= N; i++)
			{
				if (c[i][y] == '*')
					break;
				else
				{
					pair<int, int> temp = {i, y};
					if (temp == T)
						return 1;
					if (vis[i][y] == 0)
					{
						vis[i][y] = 1;
						q.push({i, y});
					}
				}
			}
			for (int i = y - 1; i >= 1; i--)
			{
				if (c[x][i] == '*')
					break;
				else
				{
					pair<int, int> temp = {x, i};
					if (temp == T)
						return 1;
					if (vis[x][i] == 0)
					{
						vis[x][i] = 1;
						q.push({x, i});
					}
				}
			}
			for (int i = y + 1; i <= M; i++)
			{
				if (c[x][i] == '*')
					break;
				else
				{
					pair<int, int> temp = {x, i};
					if (temp == T)
						return 1;
					if (vis[x][i] == 0)
					{
						vis[x][i] = 1;
						q.push({x, i});
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> c[i][j];
				if (c[i][j] == 'S')
					S = {i, j};
				if (c[i][j] == 'T')
					T = {i, j};
			}
		}
		if (is_possible())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
