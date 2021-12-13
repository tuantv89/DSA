#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005], v0, flag;
vector<vector<int>> ke;

void ChuTrinhDFS(int u, int x)
{
	if (flag == 1)
		return;
	vis[u] = 1;
	for (int i = 0; i < ke[u].size(); i++)
	{
		if (vis[ke[u][i]] == 0)
			ChuTrinhDFS(ke[u][i], u);
		else
		{
			if (ke[u][i] != x)
			{
				flag = 1;
				return;
			}
		}
	}
}

int main()
{
	int t, x, y;
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

		flag = 0;
		for (int i = 1; i <= N; i++)
		{
			if (vis[i] == 0)
			{
				ChuTrinhDFS(i, -1);
				if (flag == 1)
					break;
			}
		}
		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
