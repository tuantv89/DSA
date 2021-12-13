#include <bits/stdc++.h>
using namespace std;
int n;
char c[105][105];
pair<int, int> a, b;
int minimum_moves()
{
	queue<pair<int, int>> q;
	set<pair<int, int>> checked;
	if (a == b)
		return 0;
	int ans = 0;
	q.push(a);
	checked.insert(a);
	while (q.size())
	{
		ans++;
		int size = q.size();
		while (size--)
		{
			pair<int, int> tmp;
			tmp = q.front();
			q.pop();
			int x = tmp.first, y = tmp.second;
			for (int i = x - 1; i >= 0; i--)
			{
				if (c[i][y] == 'X')
					break;
				else
				{
					pair<int, int> temp = make_pair(i, y);
					if (temp == b)
						return ans;
					if (checked.find(temp) == checked.end())
					{
						checked.insert(temp);
						q.push(temp);
					}
				}
			}
			for (int i = x + 1; i < n; i++)
			{
				if (c[i][y] == 'X')
					break;
				else
				{
					pair<int, int> temp = make_pair(i, y);
					if (temp == b)
						return ans;
					if (checked.find(temp) == checked.end())
					{
						checked.insert(temp);
						q.push(temp);
					}
				}
			}
			for (int i = y - 1; i >= 0; i--)
			{
				if (c[x][i] == 'X')
					break;
				else
				{
					pair<int, int> temp = make_pair(x, i);
					if (temp == b)
						return ans;
					if (checked.find(temp) == checked.end())
					{
						checked.insert(temp);
						q.push(temp);
					}
				}
			}
			for (int i = y + 1; i < n; i++)
			{
				if (c[x][i] == 'X')
					break;
				else
				{
					pair<int, int> temp = make_pair(x, i);
					if (temp == b)
						return ans;
					if (checked.find(temp) == checked.end())
					{
						checked.insert(temp);
						q.push(temp);
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j];
	cin >> a.first >> a.second >> b.first >> b.second;
	cout << minimum_moves();
	return 0;
}
