#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll mini_cost(int a[], int n)
{
	priority_queue<int, vector<int>, greater<int>> pq(a, a + n);
	ll ans = 0;
	while (pq.size() > 1)
	{
		int x1 = pq.top();
		pq.pop();
		int x2 = pq.top();
		pq.pop();
		ans += (x1 + x2);
		pq.push(x1 + x2);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << mini_cost(a, n) << endl;
	}
	return 0;
}
