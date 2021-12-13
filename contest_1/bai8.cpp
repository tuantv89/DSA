#include <bits/stdc++.h>
using namespace std;
int a[11], n, check[11];
void init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		check[i] = 1;
}
void in()
{
	for (int i = 1; i <= n; i++)
		cout << a[i];
	cout << " ";
}
void Try(int i)
{
	for (int j = n; j >= 1; j--)
	{
		if (check[j])
		{
			a[i] = j;
			check[j] = 0;
			if (i == n)
				in();
			else
				Try(i + 1);
			check[j] = 1;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		init();
		Try(1);
		cout << endl;
	}
	return 0;
}
