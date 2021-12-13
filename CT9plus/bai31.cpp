#include <bits/stdc++.h>
using namespace std;
int N;
int a[1005][1005], vis[1005];
void bfs(int u)
{
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (a[v][i] && !vis[i])
			{
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}
bool LienThong()
{
	for (int i = 1; i <= N; i++)
		if (vis[i] == 0)
			return false;
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		cin >> N;
		int x, y;
		for (int i = 1; i <= N - 1; i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		bfs(1);
		if (LienThong())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
