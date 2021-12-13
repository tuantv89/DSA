#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, L, R;
ll Len(ll n)
{
	if (n == 0 || n == 1)
		return 1;
	ll tmp = Len(n / 2);
	return tmp * 2 + 1;
}
ll cnt(ll n, ll l, ll r)
{
	if (l > R || r < L)
		return 0;
	if (L <= l && r <= R)
		return n;
	ll m = (l + r) / 2;
	if (m >= L && m <= R)
		return cnt(n / 2, l, m - 1) + cnt(n / 2, m + 1, r) + n % 2;
	return cnt(n / 2, l, m - 1) + cnt(n / 2, m + 1, r);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> N >> L >> R;
		ll leng = Len(N);
		cout << cnt(N, 1, leng) << endl;
	}
	return 0;
}
