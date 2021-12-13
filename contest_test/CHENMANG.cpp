#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int dem = 1;
	while (t--)
	{
		int m, n, p;
		cin >> n >> m >> p;
		int a[n], b[m];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		cout << "Test " << dem << ":" << endl;
		if (p == 0)
		{
			for (int i = 0; i < m; i++)
				cout << b[i] << " ";
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
		}
		else
		{
			int tmp = 0;
			for (tmp = 0; tmp < p; tmp++)
				cout << a[tmp] << " ";
			for (int i = 0; i < m; i++)
				cout << b[i] << " ";
			for (int i = tmp; i < n; i++)
				cout << a[i] << " ";
		}
		cout << endl;
		dem++;
	}
	return 0;
}
