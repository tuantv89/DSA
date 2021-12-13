#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1005][1005], color[1005];
bool is_ok(int u)
{
	color[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (a[x][x] == 1)
			return false;
		for (int i = 1; i <= N; i++)
		{
			if (a[x][i] && color[i] == -1)
			{
				color[i] = 1 - color[x];
				q.push(i);
			}
			else if (a[x][i] && color[x] == color[i])
				return false;
		}
	}
	return true;
}
bool is2SideGrap()
{
	memset(color, -1, sizeof(color));
	for (int i = 1; i <= N; i++)
	{
		if (color[i] == -1)
		{
			if (!is_ok(i))
				return false;
		}
	}
	return true;
}
int main()
{
	int t, x, y;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		cin >> N >> M;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		if (is2SideGrap())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
