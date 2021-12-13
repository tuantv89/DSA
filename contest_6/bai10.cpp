#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n], d[10] = {0}, ok = 0, c = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (ok)
				continue;
			int temp = a[i];
			while (temp)
			{
				int q = temp % 10;
				temp /= 10;
				if (d[q] == 0)
				{
					d[q] = 1;
					c++;
				}
				if (c == 10)
				{
					ok = 1;
					break;
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (d[i])
				cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
