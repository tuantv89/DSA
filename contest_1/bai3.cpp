#include <bits/stdc++.h>
using namespace std;
void in(int a[], int n)
{
	int i = n - 2, ok = 1;
	while (a[i] > a[i + 1])
		i--;
	if (i >= 0)
	{
		int j = n - 1;
		while (a[j] < a[i])
			j--;
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		int r = i + 1, q = n - 1;
		while (r < q)
		{
			int tmp = a[r];
			a[r] = a[q];
			a[q] = tmp;
			r++;
			q--;
		}
	}
	else
		ok = 0;
	if (ok == 0)
	{
		for (int it = 0; it < n; it++)
			cout << it + 1 << " ";
	}
	else
	{
		for (int it = 0; it < n; it++)
			cout << a[it] << " ";
	}
	cout << endl;
}
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		in(a, n);
	}
	return 0;
}
