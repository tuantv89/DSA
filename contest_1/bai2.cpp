#include <bits/stdc++.h>
using namespace std;
void in(int a[], int n, int k)
{
	int i = k - 1, ok = 1;
	while (a[i] == n - k + i + 1)
		i--;
	if (i >= 0)
	{
		a[i]++;
		for (int j = i + 1; j < k; j++)
			a[j] = a[j - 1] + 1;
	}
	else
		ok = 0;
	if (ok == 1)
	{
		for (int j = 0; j < k; j++)
			cout << a[j] << " ";
	}
	else
	{
		for (int j = 0; j < k; j++)
			cout << j + 1 << " ";
	}
	cout << endl;
}
int main()
{
	int t, n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int a[k];
		for (int i = 0; i < k; i++)
			cin >> a[i];
		in(a, n, k);
	}
	return 0;
}
