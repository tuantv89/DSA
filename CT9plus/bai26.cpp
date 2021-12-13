#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<pair<int, int>> edges;
int find(int truoc[], int x)
{
	if (truoc[x] == -1)
		return x;
	return find(truoc, truoc[x]);
}
void Union(int truoc[], int x, int y)
{
	int x1 = find(truoc, x);
	int y1 = find(truoc, y);
	if (x1 != y1)
		truoc[x1] = y1;
}
int ChuTrinh()
{
	int truoc[N + 1];
	memset(truoc, -1, sizeof(truoc));
	for (int i = 1; i <= M; i++)
	{
		int x = find(truoc, edges[i].first);
		int y = find(truoc, edges[i].second);
		if (x == y)
			return 1;
		Union(truoc, x, y);
	}
	return 0;
}
int main()
{
	int t, x, y;
	cin >> t;
	while (t--)
	{
		edges.clear();
		cin >> N >> M;
		edges.resize(M + 1);
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			edges[i] = {x, y};
		}
		if (ChuTrinh())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
