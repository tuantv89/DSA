#include <bits/stdc++.h>
using namespace std;
void Min_number(int s, int d)
{
	if (s == 0)
	{
		if (d == 1)
			cout << 0 << endl;
		else
			cout << -1 << endl;
		return;
	}
	if (s > 9 * d)
	{
		cout << -1 << endl;
		return;
	}
	s -= 1;
	int res[d];
	for (int i = d - 1; i > 0; i--)
	{
		if (s > 9)
		{
			res[i] = 9;
			s -= 9;
		}
		else
		{
			res[i] = s;
			s = 0;
		}
	}
	res[0] = s + 1;
	for (int i = 0; i < d; i++)
		cout << res[i];
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int s, d;
		cin >> s >> d;
		Min_number(s, d);
	}
	return 0;
}
