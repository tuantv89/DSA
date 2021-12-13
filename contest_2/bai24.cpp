#include <bits/stdc++.h>
using namespace std;
int a[20], b[20], n, k, ok;
void in()
{
	int i, s = 0, c[20], m = 1;
	for (i = 1; i <= n; i++)
		s += a[i] * b[i];
	if (s == k)
	{
		ok = 1;
		for (i = 1; i <= n; i++)
		{
			if (b[i])
			{
				c[m] = a[i];
				m++;
			}
		}
		cout << "[";
		for (int i = 1; i < m - 1; i++)
		{
			cout << c[i] << " ";
		}
		cout << c[m - 1] << "] ";
	}
}
void Try(int i)
{
	int j;
	for (j = 1; j >= 0; j--)
	{
		b[i] = j;
		if (i == n)
			in();
		else
			Try(i + 1);
	}
}
int main()
{
	int t, i;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		ok = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		Try(1);
		if (ok == 0)
			cout << -1;
		cout << endl;
	}
}
