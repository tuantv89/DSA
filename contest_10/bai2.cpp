#include <bits/stdc++.h>
using namespace std;
int V, E;
vector<int> ke[15];
int vis[15], flag;
void Hamiton(int u, int cnt)
{
	if (flag == 1)
		return;
	if (cnt == V)
	{
		flag = 1;
		return;
	}
	for (int i = 0; i < ke[u].size(); i++)
	{
		if (!vis[ke[u][i]])
		{
			vis[ke[u][i]] = 1;
			cnt++;
			Hamiton(ke[u][i], cnt);
			vis[ke[u][i]] = 0;
			cnt--;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i <= 15; i++)
			ke[i].clear();
		cin >> V >> E;
		int x, y;
		for (int i = 1; i <= E; i++)
		{
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		flag = 0;
		for (int i = 1; i <= V; i++)
		{
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			Hamiton(i, 1);
			if (flag == 1)
				break;
		}
		cout << flag << endl;
	}
	return 0;
}
