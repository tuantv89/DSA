#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (arr[m] == x)
			return m;
		if (arr[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		if (binarySearch(a, 0, n - 1, x) != -1)
			cout << binarySearch(a, 0, n - 1, x) + 1 << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
