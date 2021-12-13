#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		ll a[n], b[m];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		sort(a, a + n);
		sort(b, b + m);
		vector<int> res(m + n);
		merge(a, a + n, b, b + m, res.begin());
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
