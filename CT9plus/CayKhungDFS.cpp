#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1005][1005], vis[1005];
vector<pair<int, int>> res;
void dfs(int u)
{
	vis[u] = 1;
	stack<int> st;
	st.push(u);
	while (!st.empty())
	{
		int t = st.top();
		st.pop();
		for (int i = 1; i <= N; i++)
		{
			if (a[t][i] && !vis[i])
			{
				vis[i] = 1;
				st.push(t);
				st.push(i);
				res.push_back({t, i});
				if (res.size() == N - 1)
					return;
				break;
			}
		}
	}
}
int main()
{
	int t, u;
	cin >> t;
	while (t--)
	{
		res.clear();
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		cin >> N >> M >> u;
		int x, y;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		dfs(u);
		if (res.size() < N - 1)
			cout << -1 << endl;
		else
		{
			for (int i = 0; i < res.size(); i++)
				cout << res[i].first << " " << res[i].second << endl;
		}
	}
	return 0;
}
