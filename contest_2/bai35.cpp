#include <bits/stdc++.h>
using namespace std;
int ok = 1;
void next_bin(int c[], int n)
{
	int i = n - 1;
	while (c[i] == 0)
		i--;
	if (i >= 0)
	{
		c[i] = 0;
		for (int j = i + 1; j < n; j++)
			c[j] = 1;
	}
	else
		ok = 0;
}
int check(int c[], int n, int k)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (c[i] == 1)
			cnt++;
		if (cnt > k)
			return 0;
	}
	return (cnt == k);
}
void sub_sum_k(int a[], int n, int k, int s)
{
	int c[n];
	int sum = 0, dem = 0;
	for (int i = 0; i < n; i++)
	{
		c[i] = 1;
	}
	while (ok)
	{
		sum = 0;
		for (int i = 0; i < n; i++)
			sum += c[i] * a[i];
		if (sum == s && check(c, n, k))
			dem++;
		next_bin(c, n);
	}
	cout << dem << endl;
}
int main()
{
	int n, k, s;
	while (true)
	{
		cin >> n >> k >> s;
		if (n == 0 && k == 0 && s == 0)
		{
			break;
		}
		int a[n];
		for (int i = 0; i < n; i++)
			a[i] = i + 1;
		sub_sum_k(a, n, k, s);
		ok = 1;
	}
	return 0;
}
