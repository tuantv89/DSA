#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int BDN(ll n)
{
	queue<ll> q;
	q.push(1);
	int ans = 0;
	while (!q.empty())
	{
		ll tmp = q.front();
		q.pop();
		if (tmp <= n)
		{
			ans++;
			q.push(tmp * 10);
			q.push(tmp * 10 + 1);
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		cout << BDN(n) << endl;
	}
	return 0;
}
