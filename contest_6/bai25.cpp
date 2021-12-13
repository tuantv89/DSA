#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[n];
		int min1, min2;
		min1 = min2 = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] < min1)
			{
				min2 = min1;
				min1 = a[i];
			}
			else if (a[i] < min2 && a[i] != min1)
				min2 = a[i];
		}
		if (n < 2)
		{
			cout << -1 << endl;
			continue;
		}
		if (min2 == INT_MAX)
			cout << -1 << endl;
		else
			cout << min1 << " " << min2 << endl;
	}
	return 0;
}
