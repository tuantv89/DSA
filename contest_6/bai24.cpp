#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, x;
	cin >> t;
	while (t--)
	{
		cin >> n >> x;
		int a[n], ans = -1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == x)
				ans = i + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
