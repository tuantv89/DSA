#include <bits/stdc++.h>
using namespace std;
int s, n, k, x[17];
void in()
{
	for (int i = 1; i <= n; i++)
	{
		cout << x[i];
	}
	cout << endl;
}
void Try(int i)
{
	for (int j = 0; j <= 1; j++)
	{
		x[i] = j;
		s += j;
		if (i == n && s == k)
			in();
		else if (i < n)
			Try(i + 1);
		s -= j;
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		s = 0;
		cin >> n >> k;
		Try(1);
	}
	return 0;
}
