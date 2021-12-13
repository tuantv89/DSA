#include <bits/stdc++.h>
using namespace std;
int N, M, ans, cnt;
vector<vector<int>> ke(100005);
int vis[100005];
void dfs(int i)
{
	vis[i] = 1;
	cnt++;
	ans = max(ans, cnt);
	for (int j = 0; j < ke[i].size(); j++)
	{
		if (!vis[ke[i][j]])
		{
			vis[ke[i][j]] = 1;
			dfs(ke[i][j]);
			// vis[ke[i][j]]=0;
		}
	}
}
void solve()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		vis[i] = 0;
	ke.clear();
	ke.resize(N + 5);
	int u, v;
	for (int i = 1; i <= M; i++)
	{
		cin >> u >> v;
		ke[u].push_back(v);
		ke[v].push_back(u);
	}
	ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!vis[i])
		{
			cnt = 0;
			dfs(i);
		}
	}
	cout << ans << endl;
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
