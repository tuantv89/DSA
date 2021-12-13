#include <bits/stdc++.h>
using namespace std;
typedef double db;
int N;
vector<pair<db, db>> v;
vector<pair<db, pair<int, int>>> edges;
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
	v.clear();
	edges.clear();
	cin >> N;
	v.push_back({-1, -1});
	for (int i = 1; i <= N; i++)
	{
		db x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
			{
				db x1 = v[i].first - v[j].first;
				db y1 = v[i].second - v[j].second;
				x1 *= x1;
				y1 *= y1;
				db d = sqrt(x1 + y1);
				edges.push_back({d, {i, j}});
			}
		}
	}
	sort(edges.begin(), edges.end());
	db ans = 0;
	disjointset d[N + 5];
	for (int i = 1; i <= N; i++)
	{
		d[i].rank = 0;
		d[i].parent = i;
	}
	int cnt = 0, i = 0;
	while (cnt < N - 1 && i < edges.size())
	{
		int x = find(d, edges[i].second.first);
		int y = find(d, edges[i].second.second);
		if (x != y)
		{
			cnt++;
			Union(x, y, d);
			ans += edges[i].first;
		}
		i++;
	}
	cout << fixed << setprecision(6) << ans << endl;
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
