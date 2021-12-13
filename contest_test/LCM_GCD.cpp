#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcm(ll a, ll b)
{
	return (a * b) / __gcd(a, b);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b;
		cin >> a >> b;
		cout << __gcd(a, b) << " " << lcm(a, b) << endl;
	}
	return 0;
}
