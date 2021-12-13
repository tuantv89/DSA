#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1005][1005], vis[1005];
void dfs(int u)
{
	vis[u] = 1;
	stack<int> st;
	st.push(u);
	// cout<<u<<" ";
	while (!st.empty())
	{
		int t = st.top();
		st.pop();
		for (int i = 1; i <= N; i++)
		{
			if (a[t][i] && vis[i] == 0)
			{
				// cout<<i<<" ";
				vis[i] = 1;
				st.push(t);
				st.push(i);
				break;
			}
		}
	}
	// cout<<endl;
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
			a[y][x] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
		{
			if (vis[i] == 0)
			{
				ans++;
				dfs(i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
