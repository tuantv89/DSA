#include <bits/stdc++.h>
using namespace std;
void proceed(int n)
{
	int a = 0, b = 0;
	for (int i = 0; i * 7 <= n; i++)
	{
		int j = (n - i * 7) / 4;
		if (i * 7 + j * 4 == n)
		{
			b = i;
			a = j;
		}
	}
	if (a == 0 && b == 0)
	{
		cout << "-1" << endl;
		return;
	}
	for (int i = 1; i <= a; i++)
	{
		cout << "4";
	}
	for (int i = 1; i <= b; i++)
	{
		cout << "7";
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		proceed(n);
	}
	return 0;
}
