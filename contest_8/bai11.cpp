#include <bits/stdc++.h>
using namespace std;
int snt[10000];
void init()
{
	fill(snt, snt + 10000, 1);
	snt[0] = 0;
	snt[1] = 0;
	for (int i = 2; i <= sqrt(10000); i++)
	{
		if (snt[i])
		{
			for (int j = 2 * i; j < 10000; j += i)
				snt[j] = 0;
		}
	}
}

void solve()
{
	string a, b;
	cin >> a >> b;
	if (a == b)
		cout << 0;
	else
	{
		int ans = 0;
		snt[stoi(a)] = 0;
		queue<string> q;
		q.push(a);
		while (q.size() > 0)
		{
			int tmp = q.size();
			ans++;
			while (tmp--)
			{
				string temp = q.front();
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					string r = temp;
					string s = "0123456789";
					for (int j = 0; j <= 9; j++)
					{
						if (i == 0 && j != 0)
						{
							r[i] = s[j];
							if (snt[stoi(r)])
							{
								snt[stoi(r)] = 0;
								if (r == b)
								{
									cout << ans;
									return;
								}
								else
									q.push(r);
							}
						}
						else if (i != 0)
						{
							r[i] = s[j];
							if (snt[stoi(r)])
							{
								snt[stoi(r)] = 0;
								if (r == b)
								{
									cout << ans;
									return;
								}
								else
									q.push(r);
							}
						}
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
		init();
		solve();
		cout << endl;
	}
	return 0;
}
