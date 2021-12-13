#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005];
vector<vector<int>> ke(1005);
void dfs(int u)
{
	vis[u] = 1;
	for (int i = 0; i < ke[u].size(); i++)
	{
		if (vis[ke[u][i]] == 0)
		{
			dfs(ke[u][i]);
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
	int t, u, x, y;
	cin >> t;
	while (t--)
	{
		ke.clear();
		cin >> N >> M;
		ke.resize(N + 1);
		for (int i = 1; i <= N; i++)
			vis[i] = 0;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		vector<int> res;
		for (int i = 1; i <= N; i++)
		{
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			if (i == 1)
				dfs(2);
			else
				dfs(1);
			if (!check())
				res.push_back(i);
		}
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
