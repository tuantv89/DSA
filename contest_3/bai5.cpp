#include <bits/stdc++.h>
using namespace std;
void max_diff(int n, int k, int a[])
{
	sort(a, a + n, greater<int>());
	int id = max(k, n - k);
	int x1 = accumulate(a, a + id, 0);
	int x2 = accumulate(a, a + n, 0) - x1;
	cout << x1 - x2 << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		max_diff(n, k, a);
	}
	return 0;
}
