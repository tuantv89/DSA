#include <bits/stdc++.h>
using namespace std;
bool is_ok(int x, int y)
{
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}
int bfs(pair<int, int> st, pair<int, int> en)
{
	if (st == en)
		return 0;
	int ans = 0;
	int X[] = {1, 1, 2, 2, -1, -1, -1, -2};
	int Y[] = {-2, 2, 1, -1, 2, -2, -1, 1};
	int vis[10][10];
	memset(vis, 0, sizeof(vis));
	vis[st.first][st.second] = 1;
	queue<pair<int, int>> q;
	q.push(st);
	int size;
	while (!q.empty())
	{
		ans++;
		size = q.size();
		while (size--)
		{
			pair<int, int> t = q.front();
			q.pop();
			for (int i = 0; i < 8; i++)
			{
				int a = t.first + X[i], b = t.second + Y[i];
				if (a == en.first && b == en.second)
					return ans;
				else
				{
					if (is_ok(a, b) && !vis[a][b])
					{
						q.push({a, b});
						vis[a][b] = 1;
					}
				}
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string x, y;
		cin >> x >> y;
		pair<int, int> st, en;
		st.first = x[0] - 'a' + 1;
		st.second = x[1] - '0';
		en.first = y[0] - 'a' + 1;
		en.second = y[1] - '0';
		cout << bfs(st, en) << endl;
	}
	return 0;
}
