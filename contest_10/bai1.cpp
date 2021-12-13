#include <bits/stdc++.h>
using namespace std;
int V, E, M;
int arr[15][15], color[15];
bool is_ok(int v, int color_)
{
	for (int i = 1; i <= V; i++)
		if (arr[v][i] == 1 && color_ == color[i])
			return false;
	return true;
}
bool coloring(int v)
{
	if (v == V + 1)
		return true;
	for (int i = 1; i <= M; i++)
	{
		if (is_ok(v, i))
		{
			color[v] = i;
			if (coloring(v + 1))
				return true;
			color[v] = 0;
		}
	}
	return false;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> V >> E >> M;
		memset(arr, 0, sizeof(arr));
		memset(color, 0, sizeof(color));
		for (int i = 1; i <= E; i++)
		{
			cin >> x >> y;
			arr[x][y] = 1;
			arr[y][x] = 1;
		}
		if (coloring(1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
