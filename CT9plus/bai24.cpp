#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005], v0, flag;
vector<vector<int>> ke;
void ChuTrinhBFS(int u)
{
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	vector<int> truoc(N + 1, -1);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < ke[tmp].size(); i++)
		{
			if (vis[ke[tmp][i]] == 0)
			{
				vis[ke[tmp][i]] = 1;
				q.push(ke[tmp][i]);
				truoc[ke[tmp][i]] = tmp;
			}
			else
			{
				if (truoc[tmp] != ke[tmp][i])
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1)
			break;
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
				ChuTrinhBFS(i);
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
