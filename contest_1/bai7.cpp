#include <bits/stdc++.h>
using namespace std;
int n, k, ok, x[11];
void init()
{
	ok = 1;
	cin >> n;
	k = 1;
	x[k] = n;
}
void in()
{
	cout << "(";
	cout << x[1];
	for (int i = 2; i <= k; i++)
		cout << " " << x[i];
	cout << ")";
	cout << " ";
}
void next()
{
	int i = k, j, R, S, D;
	while (i > 0 && x[i] == 1)
		i--;
	if (i > 0)
	{
		x[i] = x[i] - 1;
		D = k - i + 1;
		R = D / x[i];
		S = D % x[i];
		k = i;
		if (R > 0)
		{
			for (int j = i + 1; j <= i + R; j++)
				x[j] = x[i];
			k = k + R;
		}
		if (S > 0)
		{
			k = k + 1;
			x[k] = S;
		}
	}
	else
		ok = 0;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		init();
		while (ok)
		{
			in();
			next();
		}
		cout << endl;
	}
	return 0;
}
