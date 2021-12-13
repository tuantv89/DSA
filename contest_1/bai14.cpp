#include <bits/stdc++.h>
using namespace std;
int n, k, x[41], y[41], ok;
void init()
{
	ok = 1;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x[i];
		y[i] = x[i];
	}
}
int nghi()
{
	int i = k - 1;
	while (x[i] == n - k + i + 1)
		i--;
	if (i >= 0)
	{
		x[i]++;
		for (int j = i + 1; j < k; j++)
			x[j] = x[j - 1] + 1;
	}
	else
		ok = 0;
	if (ok == 0)
		return k;
	else
	{
		int cnt = 0;
		for (int i = 0; i < k; i++)
		{
			if (count(y, y + k, x[i]) == 0)
				cnt++;
		}
		return cnt;
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		init();
		cout << nghi() << endl;
	}
	return 0;
}
