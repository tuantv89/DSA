#include <bits/stdc++.h>
using namespace std;
int N, M;
int vis[1005], flag;
vector<vector<int>> ke;
int reStack[1005];
void ChuTrinhBFS()
{
	vector<int> BBV(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < ke[i].size(); j++)
		{
			BBV[ke[i][j]]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (BBV[i] == 0)
			q.push(i);
	}
	int cnt = 0;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < ke[t].size(); i++)
		{
			if (--BBV[ke[t][i]] == 0)
				q.push(ke[t][i]);
		}
		cnt++;
	}
	if (cnt != N)
		flag = 1;
	else
		flag = 0;
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
		ChuTrinhBFS();
		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
