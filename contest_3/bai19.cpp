#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
void unit_fraction(ull p, ull q)
{
	if (p == 0 || q == 0)
		return;
	if (q % p == 0)
	{
		cout << "1/" << q / p << endl;
		return;
	}
	ull n = q / p + 1;
	cout << "1/" << n << " + ";
	unit_fraction(n * p - q, q * n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	ull p, q;
	cin >> t;
	while (t--)
	{
		cin >> p >> q;
		unit_fraction(p, q);
	}
	return 0;
}
