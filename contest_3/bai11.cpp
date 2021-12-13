#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef unsigned long long int ll;

ll mini_time(ll a[], int n)
{
	priority_queue<ll, vector<ll>, greater<ll>> pq(a, a + n);
	ll ans = 0;
	while (pq.size() > 1)
	{
		ll x1 = pq.top();
		pq.pop();
		ll x2 = pq.top();
		pq.pop();
		ll tmp = (x1 + x2) % M;
		ans = (ans + tmp) % M;
		pq.push(tmp);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << mini_time(a, n) << endl;
	return 0;
}
