#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005], flag;
vector<vector<int>> ke;
int reStack[1005];
void ChuTrinhDFS(int u)
{
	if (flag == 1)
		return;
	if (vis[u] == 0)
	{
		vis[u] = 1;
		reStack[u] = 1;
		for (int i = 0; i < ke[u].size(); i++)
		{
			if (vis[ke[u][i]] == 0)
				ChuTrinhDFS(ke[u][i]);
			else if (reStack[ke[u][i]])
			{
				flag = 1;
				return;
			}
		}
	}
	reStack[u] = 0;
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
		{
			vis[i] = 0;
			reStack[i] = 0;
		}
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			ke[x].push_back(y);
			// ke[y].push_back(x);
		}

		flag = 0;
		for (int i = 1; i <= N; i++)
		{
			ChuTrinhDFS(i);
			if (flag == 1)
				break;
		}
		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
