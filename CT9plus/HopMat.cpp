#include <bits/stdc++.h>
using namespace std;
int K, N, M, pos[105], vis[1005], cnt[1005];
vector<int> ke[1005];
void bfs(int u)
{
	vis[u] = 1;
	queue<int> q;
	q.push(u);
	cnt[u]++;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < ke[t].size(); i++)
		{
			if (!vis[ke[t][i]])
			{
				vis[ke[t][i]] = 1;
				cnt[ke[t][i]]++;
				q.push(ke[t][i]);
			}
		}
	}
}
int main()
{
	int x, y;
	cin >> K >> N >> M;
	for (int i = 1; i <= K; i++)
		cin >> pos[i];
	for (int i = 1; i <= M; i++)
	{
		cin >> x >> y;
		ke[x].push_back(y);
	}
	for (int i = 1; i <= K; i++)
	{
		memset(vis, 0, sizeof(vis));
		bfs(pos[i]);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (cnt[i] == K)
			ans++;
	}
	cout << ans;
	return 0;
}
