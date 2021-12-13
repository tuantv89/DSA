#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005];
vector<vector<int>> ke(1005);
int BBR[1005], BBV[1005]; // ban bac ra, vao
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
		// ke.clear();
		cin >> N >> M;
		// ke.resize(N+1);
		memset(BBR, 0, sizeof(BBR));
		memset(BBV, 0, sizeof(BBV));
		for (int i = 1; i <= N; i++)
			vis[i] = 0;
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			BBR[x]++;
			BBV[y]++;
		}
		int flag = 1;
		for (int i = 1; i <= N; i++)
			if (BBR[i] != BBV[i])
			{
				flag = 0;
				break;
			}
		cout << flag << endl;
	}
	return 0;
}
