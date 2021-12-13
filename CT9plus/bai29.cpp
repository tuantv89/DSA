#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005];
vector<vector<int>> ke;
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
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (ke[i].size() % 2 == 1)
				cnt++;
		}
		if (cnt == 0)
			cout << 2 << endl;
		else if (cnt == 2)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
