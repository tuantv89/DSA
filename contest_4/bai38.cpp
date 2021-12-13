#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int a[n], b[m];
		vector<int> res(m + n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + m);
		merge(a, a + n, b, b + m, res.begin());
		cout << res[k - 1] << endl;
	}
	return 0;
}
