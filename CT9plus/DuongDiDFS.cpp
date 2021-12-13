#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1005][1005], truoc[1005];
void dfs(int u)
{
	truoc[u] = u;
	stack<int> st;
	st.push(u);
	while (!st.empty())
	{
		int t = st.top();
		st.pop();
		for (int i = 1; i <= N; i++)
		{
			if (a[t][i] && !truoc[i])
			{
				truoc[i] = t;
				st.push(t);
				st.push(i);
				break;
			}
		}
	}
}

int main()
{
	int t, u, v;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(truoc, 0, sizeof(truoc));
		cin >> N >> M >> u >> v;
		int x, y;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		dfs(u);
		if (truoc[v] == 0)
			cout << -1 << endl;
		else
		{
			int cnt = 1;
			while (truoc[v] != u)
			{
				cnt++;
				v = truoc[v];
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
