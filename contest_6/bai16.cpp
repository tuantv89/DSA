#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int l, int h)
{
	int m = a[h];
	int i = l - 1;
	for (int j = l; j <= h - 1; j++)
	{
		if (a[j] < m)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[h]);
	return (i + 1);
}
void quick_sort(int a[], int l, int h)
{
	if (l < h)
	{
		int m = partition(a, l, h);
		quick_sort(a, l, m - 1);
		quick_sort(a, m + 1, h);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		quick_sort(a, 0, n - 1);
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
