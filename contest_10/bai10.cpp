#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
struct disjointset
{
	int rank;
	int parent;
};
int find(disjointset d[], int x)
{
	if (d[x].parent != x)
		d[x].parent = find(d, d[x].parent);
	else
		return d[x].parent;
}
void Union(int x, int y, disjointset d[])
{
	int x1 = find(d, x), y1 = find(d, y);
	if (d[y1].rank > d[x1].rank)
	{
		d[x1].parent = d[y1].parent;
		d[y1].rank++;
	}
	else
	{
		d[y1].parent = d[x1].parent;
		d[x1].rank++;
	}
}
void Kruskal()
{
	cin >> N >> M;
	disjointset d[N + 5];
	for (int i = 1; i <= N; i++)
	{
		d[i].rank = 0;
		d[i].parent = i;
	}
	vector<pair<int, pair<int, int>>> edges;
	int u, v, c;
	for (int i = 1; i <= M; i++)
	{
		cin >> u >> v >> c;
		edges.push_back(make_pair(c, make_pair(u, v)));
	}
	sort(edges.begin(), edges.end());
	int cnt = 0, i = 0;
	ll Min = 0;
	while (cnt < N - 1 && i < edges.size())
	{
		int x = find(d, edges[i].second.first);
		int y = find(d, edges[i].second.second);
		if (x != y)
		{
			cnt++;
			Union(x, y, d);
			Min += edges[i].first;
		}
		i++;
	}
	cout << Min << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Kruskal();
	}
	return 0;
}
