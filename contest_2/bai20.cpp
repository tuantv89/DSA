#include <bits/stdc++.h>
using namespace std;
void print_tamgiac(int a[], int n)
{
	if (n < 1)
		return;
	int temp[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		int x = a[i] + a[i + 1];
		temp[i] = x;
	}
	print_tamgiac(temp, n - 1);
	cout << "[";
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
			cout << a[i] << "]"
				 << " ";
		else
			cout << a[i] << " ";
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
		print_tamgiac(a, n);
		cout << endl;
	}
	return 0;
}
