#include <bits/stdc++.h>
using namespace std;
void unsorted(int a[], int n)
{
	int l = 0, r = n - 1;
	for (l = 0; l < n - 1; l++)
	{
		if (a[l] > a[l + 1])
			break;
	}
	for (r = n - 1; r > 0; r--)
	{
		if (a[r] < a[r - 1])
			break;
	}
	int min = a[l], max = a[l];
	for (int i = l; i <= r; i++)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	for (int i = 0; i < l; i++)
	{
		if (a[i] > min)
		{
			l = i;
			break;
		}
	}
	for (int i = n - 1; i > r; i--)
	{
		if (a[i] < max)
		{
			r = i;
			break;
		}
	}
	cout << l + 1 << " " << r + 1 << endl;
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
		unsorted(a, n);
	}
	return 0;
}
