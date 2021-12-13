#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1005][1005], vis[1005];
void bfs(int u)
{
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		// cout<<t<<" ";
		for (int i = 1; i <= N; i++)
		{
			if (a[t][i] && vis[i] == 0)
			{
				vis[i] = 1;
				q.push(i);
			}
		}
	}
	// cout<<endl;
}
bool lienthong()
{
	for (int i = 1; i <= N; i++)
		if (vis[i] == 0)
			return false;
	return true;
}
int main()
{
	int t, u, x, y;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		cin >> N >> M;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
			// a[y][x]=1;
		}
		bfs(1);
		if (lienthong())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
