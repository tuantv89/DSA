#include <bits/stdc++.h>
using namespace std;
int A, B, C;
char c[35][35][35];
int check[35][35][35];
pair<pair<int, int>, int> s, e;
bool is_ok(int x, int y, int z)
{
	if (x >= 0 && x < A && y >= 0 && y < B && z >= 0 && z < C)
		return true;
	return false;
}
int MoveSpace()
{
	if (s == e)
		return 0;
	queue<pair<pair<int, int>, int>> q;
	;
	q.push(s);
	int ans = 0;
	while (!q.empty())
	{
		ans++;
		int size = q.size();
		while (size--)
		{
			pair<pair<int, int>, int> tmp = q.front();
			q.pop();
			int X[] = {0, 0, 0, 0, 1, -1};
			int Y[] = {0, 0, 1, -1, 0, 0};
			int Z[] = {1, -1, 0, 0, 0, 0};
			int x = tmp.first.first, y = tmp.first.second, z = tmp.second;
			for (int i = 0; i < 6; i++)
			{
				if (c[x + X[i]][y + Y[i]][z + Z[i]] != '#' && is_ok(x + X[i], y + Y[i], z + Z[i]) && check[x + X[i]][y + Y[i]][z + Z[i]] == 0)
				{
					pair<pair<int, int>, int> temp = make_pair(make_pair(x + X[i], y + Y[i]), z + Z[i]);
					if (temp == e)
						return ans;
					else
					{
						q.push(temp);
						check[x + X[i]][y + Y[i]][z + Z[i]] = 1;
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(check, 0, sizeof(check));
		cin >> A >> B >> C;
		for (int i = 0; i < A; i++)
		{
			for (int j = 0; j < B; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> c[i][j][k];
					if (c[i][j][k] == 'S')
					{
						s = make_pair(make_pair(i, j), k);
						check[i][j][k] = 1;
					}
					else if (c[i][j][k] == 'E')
						e = make_pair(make_pair(i, j), k);
				}
			}
		}
		cout << MoveSpace() << endl;
	}
	return 0;
}
